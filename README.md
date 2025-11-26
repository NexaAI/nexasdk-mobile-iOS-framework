# Nexa SDK — iOS Framework

This repository contains the Nexa SDK packaged for iOS as an XCFramework. 

## Requirements

- Xcode 16 or later (recommended).

## Installation

You can integrate the Nexa SDK into your app using one of the following methods.

1) Manual (XCFramework)

- In Xcode, download and drag `Frameworks/NexaSdk.xcframework` into your Project/Workspace.
- Make sure the framework is added to the target's **Frameworks, Libraries, and Embedded Content** and set to **Embed & Sign** if you need the framework bundled in the app.

2) Swift Package (SPM)

```Swift
dependencies: [
    .package(url: "git@github.com:NexaAI/nexasdk-mobile-iOS-framework.git", branch: "main")
]
```

## Quick Usage (Swift)

```swift
import NexaSdk

let llm = try LLM()

let repoDir: URL = "..."
try await llm.load(from: repoDir)

let stream = await llm.generateAsyncStream(prompt: "Hello, Tell me a story")
for try await token in stream {
    print(token, terminator: "")
}
```

### 2. Example for VLM:

```swift
import NexaSdk

let vlm = try VLM()

let repoDir: URL = "..."
try await vlm.load(from: repoDir)

let stream = await vlm.generateAsyncStream(prompt: "Hello, Tell me a story")
for try await token in stream {
    print(token, terminator: "")
}
```

### 3. Example for Embedder:

```swift
import NexaSdk

let repoDir: URL = "..."
let embedder = try Embedder(from: repoDir, plugin: .ane)

let texts = [
    "Hello world", "Good morning",
    "Machine learning is fascinating",
    "Natural language processing"
]
let result = try embedder.embed(texts: texts, config: .init(batchSize: texts.count))
print(result.embeddings.prefix(10))
```

### 4. Example for Embedder:

```swift
import NexaSdk

let repoDir: URL = "..."
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

```
### 5. Example for Asr

```swift

let repoDir: URL = "..."
let asr = try Asr()
try await asr.load(from: repoDir)

print(asr.supportedLanguages())

let audioPath = Bundle.main.path(forResource: "test", ofType: "wav")!
let result = try await asr.transcribe(options: .init(audioPath: audioPath))

print(result.asrResult)

```

### 6. Other

```swift
// setup log
NexaAI.install([.error, .trace, .debug])

// version
print(NexaAI.version)

```