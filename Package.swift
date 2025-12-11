// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "NexaSdk",
    platforms: [.iOS(.v17), .macOS("15.0")],
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(name: "NexaSdk", targets: ["NexaSdk"])
    ],
    
    targets: [
        .binaryTarget(
            name: "NexaSdk",
            path: "Frameworks/NexaSdk.xcframework"
        ),
        .testTarget(
            name: "NexaSdkTests",
            dependencies: ["NexaSdk"]
        ),
    ]
)
