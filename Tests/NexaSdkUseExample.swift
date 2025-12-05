import Testing
import Foundation
import NexaSdk

struct NexaSdkUseExample {

    init() {
        // setup log
        // NexaAI.install([.error, .trace, .debug])
        NexaAI.install()
        
        // version
        print(NexaAI.version)

    }

    func asrExample() async throws {
        let repoDir: URL = URL(string: "...")!
        let asr = try Asr()
        try await asr.load(from: repoDir)

        print(asr.supportedLanguages())

        let audioPath = Bundle.main.path(forResource: "test", ofType: "wav")!
        let result = try await asr.transcribe(options: .init(audioPath: audioPath))

        print(result.asrResult)
    }

    
    func embedderExample() async throws {
        let repoDir: URL = URL(string: "...")!
        let embedder = try Embedder(from: repoDir, plugin: .ane)

        let texts = [
            "Hello world", "Good morning",
            "Machine learning is fascinating",
            "Natural language processing"
        ]
        let result = try embedder.embed(texts: texts, config: .init(batchSize: Int32(texts.count)))
        print(result.embeddings.prefix(10))
    }

    func rerankerExample() async throws {
        let repoDir: URL = URL(string: "...")!
        let reranker = try Reranker(from: repoDir)
        let query = "What is machine learning?"
        let documents = [
            "Machine learning is a subset of artificial intelligence that enables computers to learn and make decisions ",
            "without being explicitly programmed.",
            "Machine learning algorithms build mathematical models based on sample data to make predictions or decisions.",
            "Deep learning is a subset of machine learning that uses neural networks with multiple layers.",
            "Python is a popular programming language for machine learning and data science.",
            "The weather today is sunny and warm."
        ]
        let result = try await reranker.rerank(query, documents: documents)
        print(result.scores)
    }

    func llmExample() async throws {
        let llm = try LLM()
        let repoDir: URL = URL(string: "...")!
        try await llm.load(from: repoDir)

        let stream = await llm.generateAsyncStream(prompt: "Hello, Tell me a story")
        for try await token in stream {
            print(token, terminator: "")
        }
    }

    func vlmExample() async throws {
        let vlm = try VLM()

        let repoDir: URL = URL(string: "...")!
        try await vlm.load(from: repoDir)

        let stream = await vlm.generateAsyncStream(prompt: "Hello, Tell me a story")
        for try await token in stream {
            print(token, terminator: "")
        }
    }

}
