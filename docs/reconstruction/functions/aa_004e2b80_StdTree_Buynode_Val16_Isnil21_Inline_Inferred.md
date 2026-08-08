# Function record: StdTree_Buynode_Val16_Isnil21_Inline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2b80` |
| **Canonical name** | `StdTree_Buynode_Val16_Isnil21_Inline_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004e2b80` |
| **Address** | `0x004e2b80` |
| **Body** | `0x004e2b80`–`0x004e2bce` inclusive (**79 B** / `0x4F`); pad `CC` @ `0x004e2bcf` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition); MSVC `std::_Tree` node allocation |
| **Agent** | R13-004 OWN-ONLY dual 2026-08-05 (dual start 2686) |
| **Parent dual** | `0x004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (R12-012) |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |
| **Runtime** | **Open** — never Runtime Confirmed |

## Alias history

- Ghidra: `FUN_004e2b80`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Updat_004e2b80`
- Structural: `StdTree_Buynode_Val16_Isnil21_Inline_Inferred` (product demangle open)

## Purpose

MSVC-style `_Tree` buynode for the **isnil@+0x21** family with **16-byte (4 dword) value** at `+0x10`. Allocates **0x28**, constructs links + value + color + isnil=0 **inline** (no SEH, no separate NodeCtor). Returns null on OOM. Used by dualed insert/rebalance `FUN_004e37e0` and residual peer `FUN_005a3500`.

## Signature

```c
NodeIsnil21* __stdcall StdTree_Buynode_Val16_Isnil21_Inline_Inferred(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const uint32_t value4[4],
    uint8_t color);
// RET 0x14; EAX = node* | null
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | not written on this path |
| +0x10 | value (4× int32 / Val16) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil (forced 0) |
| size | **0x28** |

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_004e37e0` @ `0x004e3872` (dualed R12-012 insert/rebalance) |
| **Caller** | `FUN_005a3500` @ `0x005a3592` (peer insert clone; residual) |
| Alloc | `operator_new(0x28)` |
| Contrast peer buynode | `0x00408990` `StdTree_Buynode_Val16_Isnil21_Inferred` (SEH + ctor) |
| Contrast NodeCtor | `0x004099b0` construct-only |
| Contrast empty | `0x004088f0` empty head shell |
| Contrast Val24 | `0x00407e30` / `0x005a2de0` |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 0x14` via `read_memory` / disasm.
- Insert parents pass color **0** → red node; color checks @+0x20 in rebalance.
- Decompiler `void` is display gap; callers consume EAX.
- Prior CVOGReaction chain scaffold **retired**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val16_Isnil21_Inline_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_004e2b80.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Updat_004e2b80.cpp`
- Raw: `docs/reconstruction/raw/aa_004e2b80_FUN_004e2b80.md`
- Annotated: `docs/reconstruction/raw/aa_004e2b80_FUN_004e2b80.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md`
- Report: `docs/agents/task-dual-ab-004e2b80-r13-report.md`

## Confidence

| Claim | Level |
|---|---|
| Role buynode Val16 isnil21 inline | **High** |
| ABI / RET 0x14 / EAX return | **High** (byte-sealed) |
| Layout color@+0x20 isnil@+0x21 node 0x28 Val16 | **High** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
