# Function record: StdList_BuyNode_Dword

| Field | Value |
|---|---|
| **Stable ID** | `aa_006759b0` |
| **Canonical name** | `StdList_BuyNode_Dword` (**Inferred**) |
| **Ghidra symbol** | `FUN_006759b0` |
| **Address** | `0x006759b0` |
| **Body** | `0x006759b0`–`0x006759d6` (39 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` node helper |
| **Completion status** | **Sealed** — W20-M dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Verdict** | **accept** |

## Alias

- `FUN_006759b0`
- `Named_CalleeOf_Auth_AuthServer_006759b0` (**misleading** parent-seed; Auth is only one of many callers)

## Purpose

Allocate a **0xC-byte** list node via `operator_new` and initialize three dwords: link0, link1, `*pValue`. Shared `_Buynode`-shaped leaf for pointer/dword-sized `std::list` elements across the client.

## Signature

```c
// __stdcall, ret 0xC; returns node* in EAX (0 on alloc fail)
void *StdList_BuyNode_Dword(void *link0, void *link1, uint32_t *pValue);
```

## Node layout

| Off | Field |
|---|---|
| `+0x00` | link0 (arg1) |
| `+0x04` | link1 (arg2) |
| `+0x08` | value dword (`*arg3`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006759b0_FUN_006759b0.md`
- Annotated: `docs/reconstruction/raw/aa_006759b0_FUN_006759b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdList_BuyNode_Dword.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_006759b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_006759b0_StdList_BuyNode_Dword.md`
- Review B: `docs/reconstruction/reviews/B_aa_006759b0_StdList_BuyNode_Dword.md`

## Callers / callees

**Callees:** `operator_new` only.

**Callers (sample of 40+):** `FUN_00480350` (StdList_PushPayloadNode), `FUN_00491e80`, Auth send paths (`00728840`…), `FUN_004a0b90`×4, `FUN_007c8890`×2, many others. Role is generic — not Auth-specific.

## Confidence

| Claim | Level |
|---|---|
| CF: new 0xC + three dword stores + null gate | **High** |
| ABI `__stdcall` `ret 0xc` | **High** (byte seal) |
| Returns node* in EAX | **High** (callers assign) |
| Shared list-node helper | **High** (xref flood + call pattern) |
| Product PDB symbol | **Open** |
| Link0/link1 = prev/next polarity | **Medium** (caller-defined) |
