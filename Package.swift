// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "NexaSdk",
    platforms: [.macOS(.v14), .iOS(.v17)],
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(name: "common", targets: ["common"]),
        .library(name: "llama", targets: ["llama"]),
        .library(name: "mtmd", targets: ["mtmd"]),
        .library(name: "ggml", targets: ["ggml"]),
        .library(name: "ggml-base", targets: ["ggml-base"]),
        .library(name: "ggml-cpu", targets: ["ggml-cpu"]),
        .library(name: "ggml-metal", targets: ["ggml-metal"]),
        .library(name: "NexaBridge", targets: ["NexaBridge"]),
        .library(name: "LlamaPlugin", targets: ["LlamaPlugin"])
    ],

    targets: [
        .binaryTarget(
            name: "NexaBridge",
            path: "Frameworks/libnexa_bridge.xcframework"
        ),

        .binaryTarget(
            name: "LlamaPlugin",
            path: "Frameworks/libnexa_plugin.xcframework"
        ),

        .binaryTarget(
            name: "ggml",
            path: "Frameworks/libggml.xcframework"
        ),

        .binaryTarget(
            name: "ggml-base",
            path: "Frameworks/libggml-base.xcframework"
        ),

        .binaryTarget(
            name: "ggml-cpu",
            path: "Frameworks/libggml-cpu.xcframework"
        ),

        .binaryTarget(
            name: "ggml-metal",
            path: "Frameworks/libggml-metal.xcframework"
        ),

        .binaryTarget(
            name: "llama",
            path: "Frameworks/libllama.xcframework"
        ),

        .binaryTarget(
            name: "common",
            path: "Frameworks/libcommon.xcframework"
        ),

        .binaryTarget(
            name: "mtmd",
            path: "Frameworks/libmtmd.xcframework"
        ),
    ]
)
