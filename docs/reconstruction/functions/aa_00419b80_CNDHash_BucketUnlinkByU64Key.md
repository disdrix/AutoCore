# Function record: CNDHash_BucketUnlinkByU64Key (`FUN_00419b80`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419b80` |
| **Canonical name** | `CNDHash_BucketUnlinkByU64Key` (inferred) |
| **Ghidra name** | `FUN_00419b80` |
| **Address** | `0x00419b80` |
| **Body** | `0x00419b80`–`0x00419bc9` (73 bytes; `ret 8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (u64-key inventory-sheet family) |
| **Completion status** | **Dual A/B sealed** (W18-P, 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Prior scaffold: `Named_CalleeOf_Named_VOG_DEBUG_STOP_00419b80`
- Ghidra: `FUN_00419b80`

## Purpose

**Find + unlink** a u64-keyed node from a single CNDHash **bucket chain**, then run bucket chain touch/cycle repair. Returns the unlinked **node*** (does not free, does not touch ordered list / freelist / value dtor — parent `CNDHash_Remove_u64` does that).

## Signature (machine)

```c
// EBX = BucketHeader*
// __stdcall stack: keyLo, keyHi  → ret 8
// return EAX = Node* or NULL
Node *CNDHash_BucketUnlinkByU64Key(uint32_t keyLo, uint32_t keyHi);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00419b80_FUN_00419b80.md`
- Annotated: `docs/reconstruction/raw/aa_00419b80_FUN_00419b80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_BucketUnlinkByU64Key.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00419b80.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md`
- Review B: `docs/reconstruction/reviews/B_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md`
- Scaffold record: `docs/reconstruction/functions/aa_00419b80_FUN_00419b80.md`

## Callers / callees

**Callees:**

| VA | Name | Role |
|---|---|---|
| `0x00419b40` | `CNDHash_BucketFindNodeByU64Key` | find + predOut |
| `0x00419ad0` | `FUN_00419ad0` | bucket chain touch-bit walk / cycle cut |

**Callers:**

| VA | Role |
|---|---|
| `0x00413a60` | `CNDHash_Remove_u64` |
| `0x004197b0` | related remove path |

## Confidence

| Claim | Level |
|---|---|
| Control flow + offsets + `ret 8` | **Confirmed** (body bytes) |
| EBX bucket / predOut keyLo-slot reuse | **Confirmed** (body bytes) |
| Splice `pred->next` vs `head` | **Confirmed** |
| Always call ad0 before return | **Confirmed** |
| Product English name | **Probable** (inferred) |
| Runtime harness | **Open** |
