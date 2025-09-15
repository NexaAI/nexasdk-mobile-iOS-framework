#pragma once

/**
 * @file IValidatable.h
 * @brief Generic validation interface template for plugin modalities
 *
 * This header contains the IValidatable template interface that provides
 * validation capabilities for any plugin modality. Implementation classes
 * can optionally inherit from this interface to add validation support.
 */

#include "logging.h"
#include "ml.h"
#ifdef NEXA_VALIDATION
#include "validation/validation.h"
#endif

namespace nexa {

// =============================================================================
// Helper Functions
// =============================================================================

/**
 * @brief Convert validation result code to ML error code
 * @param validation_result_code The validation result code from validation system
 * @return Corresponding ML error code
 */
inline int32_t validation_result_to_ml_error(int validation_result_code) {
    switch (validation_result_code) {
        case 0:
            return ML_SUCCESS;
        case 2:
            return ML_ERROR_COMMON_LICENSE_EXPIRED;
        default:
            return ML_ERROR_COMMON_LICENSE_INVALID;
    }
}

// =============================================================================
// Validatable Interface Template
// =============================================================================

/**
 * @brief Generic interface for validation logic
 * @tparam CreateInput The type of creation input to validate (e.g., ml_LlmCreateInput)
 *
 * This interface encapsulates the validation concern and can be composed
 * with any plugin interface to add validation capabilities.
 */
template <typename CreateInput>
class IValidatable {
   public:
    virtual ~IValidatable() = default;

    /**
     * @brief Determine if validation is needed for the given creation input
     * @param input The creation input to check for validation requirements
     * @return true if validation should be performed, false otherwise
     */
    virtual bool is_validation_needed(const CreateInput* input) = 0;

    /**
     * @brief Generic validation logic that can be used by all modalities
     * @param input The creation input to validate
     * @return ML error code (ML_SUCCESS on success, negative on failure)
     */
    int32_t validate(const CreateInput* input) {
        if (!input) {
            NEXA_LOG_ERROR("Create input is nullptr");
            return ML_ERROR_COMMON_INVALID_INPUT;
        }

        // Check if validation is needed (entirely compiled out when validation is disabled)
#ifdef NEXA_VALIDATION
        if (is_validation_needed(input)) {
            NEXA_LOG_INFO("Validation required, performing validation checks...");

            // Pass empty strings to validate_license since license tokens are resolved
            // via environment variables, not from CreateInput structs
            auto validation_result = nexa::validation::validate_license("", "");
            if (validation_result.result != 0) {
                NEXA_LOG_ERROR("Validation failed: {}", fmt::to_string(validation_result.message));
                return validation_result_to_ml_error(validation_result.result);
            }

            NEXA_LOG_INFO("Validation passed");
        }
#else
        NEXA_LOG_INFO("Validation skipped (validation disabled)");
#endif

        return ML_SUCCESS;
    }
};

}  // namespace nexa
