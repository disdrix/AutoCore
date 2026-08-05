# Function record: Map_EraseNode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005399f0` |
| **Canonical name** | `Map_EraseNode_Val12` (**Inferred**) |
| **Ghidra name** | `FUN_005399f0` |
| **Address** | `0x005399f0` |
| **Body** | `0x005399f0`–`0x00539ca6` exclusive (**694** B / `0x2B6`) |
| **Ghidra listed end** | `0x00539c76` (**stale** — `operator_delete` noreturn truncate) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map/set red-black erase (Val12) |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W27-R 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005399f0_Map_EraseNode_Val12.md`, `reviews/B_aa_005399f0_Map_EraseNode_Val12.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- Ghidra: `FUN_005399f0`
- Structural: `Map_EraseNode_Val12`
- Peer (different layout): `Map_EraseNode` `aa_0051cb40` (isnil@+0x29)

## Purpose

Erase one non-nil **Val12** red-black node: invalid-iterator throw, splice + head fixup, black-node RB rebalance, `operator_delete`, **size--**, publish successor to `*outIt`.

## Signature (sealed)

```c
void __thiscall Map_EraseNode_Val12(
    MapShell_Val12* map,     // ECX; head@+4, size@+8
    MapNode_Val12** outIt,   // successor out
    MapNode_Val12* node);    // node to erase
// RET 8
```

## Layout

| Offset | Field |
|---|---|
| node +0x18 | color (0 red, 1 black) |
| node +0x19 | isnil |
| map +0x04 | head sentinel |
| map +0x08 | size |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005399f0_FUN_005399f0.md` (+ W27-R append)
- Annotated: `docs/reconstruction/raw/aa_005399f0_FUN_005399f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_EraseNode_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005399f0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005399f0_FUN_005399f0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005399f0-00567450-w27r-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_005ae0b0`, `FUN_005adfa0`, `FUN_00418bf0`, `FUN_00573170`, `FUN_00418c10`, `operator_delete`, `_CxxThrowException`, STL string/exception |
| **Callers (1)** | `FUN_0053a260` (range erase) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompile through delete | **High** |
| Post-delete size-- / ret 8 from bytes | **High** |
| Val12 isnil@+0x19 / color@+0x18 | **High** |
| Throw string + ThrowInfo | **High** |
| Name product / demangle | **Inferred** |
| Full RB case line-by-line vs MSVC ref | **Tentative** (contract High) |
| Runtime / differential | Open |
