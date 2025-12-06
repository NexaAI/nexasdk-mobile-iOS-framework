# Nexa SDK — iOS/macOS Framework

This repository contains the Nexa SDK packaged for iOS/macOS as an XCFramework. 

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

### Example for Asr

```swift
import NexaSdk
import Foundation

let repoDir: URL = URL(string: "...")!
let asr = try Asr()
try await asr.load(from: repoDir)

print(asr.supportedLanguages())

let audioPath = Bundle.main.path(forResource: "test", ofType: "wav")!
let result = try await asr.transcribe(options: .init(audioPath: audioPath))

print(result.asrResult)

```

### Example for Embedder:

```swift
import NexaSdk
import Foundation

let repoDir: URL = URL(string: "...")
let embedder = try Embedder(from: repoDir)

let texts = [
    "Hello world", "Good morning",
    "Machine learning is fascinating",
    "Natural language processing"
]
let result = try embedder.embed(texts: texts, config: .init(batchSize: Int32(texts.count)))
print(result.embeddings.prefix(10))
```

### Example for LLM
```swift
import NexaSdk
import Foundation


let llm = try LLM()

let repoDir: URL = URL(string: "...")!
try await llm.load(from: repoDir)

var messages: [ChatMessage] = [
    ChatMessage(role: .user, content: "Hello, Tell me a story")
]

// Round 1: Generate a story
print("User: Hello, Tell me a story\n")
print("Assistant: ", terminator: "")
var prompt = try await llm.applyChatTemplate(messages: messages)
var stream = await llm.generateAsyncStream(prompt: prompt)
var response = ""
for try await token in stream {
    print(token, terminator: "")
    response += token
}
print("\n")

// Append assistant response and ask follow-up
messages.append(ChatMessage(role: .assistant, content: response))
messages.append(ChatMessage(role: .user, content: "What is the title of the story?"))

// Round 2: Ask about the title
print("User: What is the title of the story?\n")
print("Assistant: ", terminator: "")
prompt = try await llm.applyChatTemplate(messages: messages)
stream = await llm.generateAsyncStream(prompt: prompt)
for try await token in stream {
    print(token, terminator: "")
}
print()
```

### Example for VLM:

```swift
import NexaSdk
import Foundation

let vlm = try VLM()

let repoDir: URL = URL(string: "...")!
try await vlm.load(from: repoDir)

let imagePath = "path/to/your/image"
let messages: [ChatMessage] = [
    ChatMessage(role: .user, content: "What is in this image?", images: [imagePath])
]

let prompt = try await vlm.applyChatTemplate(messages: messages)
let config = GenerationConfig(imagePaths: [imagePath])
let stream = await vlm.generateAsyncStream(prompt: prompt, config: config)
for try await token in stream {
    print(token, terminator: "")
}
```

### Example for Reranker:

```swift
import NexaSdk
import Foundation

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

```

### Other

```swift
// setup log
NexaAI.install([.error, .trace, .debug])

// version
print(NexaAI.version)

```
