# Function record: TNL_ByteBuffer_UnpackData

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637750` |
| **Canonical name** | `TNL_ByteBuffer_UnpackData` |
| **Address** | `0x00637750` |
| **Body** | `0x00637750`–`0x00637982` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-net / TNL special-message |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 (wire + rebuild + ABI) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Unpack TNL special-message opcode **`0x804D`** (`MapInstanceListResponse`) from an inbound refcounted byte buffer into a newly allocated **TNL ByteBuffer** whose data prefix is `{ tag 0x804D, count, Entry* }`, with `count` map-instance entries of stride **`0x18`** on the heap.

Sole caller: `Client_UnpackSpecialMessage` (`aa_00637c20`).

## Signature (sealed)

```c
void** TNL_ByteBuffer_UnpackData(void** outByteBuffer, RefCountedBuffer* inBuf);
// cdecl; returns outByteBuffer; *outByteBuffer = ByteBuffer* (refcount 1)
```

## Wire format (sealed)

```
u8  count
repeat count:
  u64 id
  u16 fieldA
  u16 fieldB
  bit flag0
  bit flag1
```

## Rebuild layouts (sealed)

**Entry (0x18):** u64 @+0, u16→u32 @+8, u16→u32 @+0xC, bool @+0x10, bool @+0x11.

**ByteBuffer object (0x18):** vtable `PTR_LAB_009d7b00`, refcount @+8, data @+0xC, size @+0x10 (`count*0x18+8`), owns @+0x14.

**Data prefix:** `u32 tag=0x804D`, `u32 count`, `Entry* entries`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00637750_FUN_00637750.md`
- Annotated: `docs/reconstruction/raw/aa_00637750_FUN_00637750.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TNL_ByteBuffer_UnpackData.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00637750_TNL_ByteBuffer_UnpackData.md`
- Review B: `docs/reconstruction/reviews/B_aa_00637750_TNL_ByteBuffer_UnpackData.md`
- Dual report: `docs/agents/task-dual-ab-00637750-tnl-bytebuffer-unpackdata-report.md`
- Scaffold twin: `docs/reconstruction/functions/aa_00637750_FUN_00637750.md` (superseded by this record)

## Callers / callees

| Direction | Targets |
|---|---|
| **Callers** | `Client_UnpackSpecialMessage` only (`0x00637d68`) |
| **Callees** | `FUN_0042b3a0` (BitStream from buffer), `BitStream_readBits`, `FUN_0042b250` / `FUN_0042b270` (ref base), `operator_new` / `operator_new[]`, `malloc` / `free` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI cdecl / body range | **High** (bytes + decompile) |
| Opcode 0x804D / sole caller | **High** |
| Wire u8 + (u64,u16,u16,flag,flag)×N | **High** |
| Entry stride 0x18 + field offsets | **High** |
| ByteBuffer vtable / size / owns / refcount | **High** |
| Data prefix `{tag,count,Entry*}` | **High** (consumer `FUN_0080a810` cross-check) |
| Entry field English names / u64 identity | **Tentative** |
| Runtime / bit-exact | Open |

## Dual A/B

| Review | Verdict |
|---|---|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |
