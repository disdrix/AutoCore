# Function record: Map_EraseNode_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051ce00` |
| **Canonical name** | `Map_EraseNode_Isnil15` |
| **Ghidra name** | `FUN_0051ce00` |
| **Address** | `0x0051ce00`–`0x0051d0b5` inclusive (**694 bytes** / exclusive end `0x0051d0b6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (isnil@+0x15 single-node erase; skills-abilities residual neighborhood) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-G OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style red-black **single-node erase** for the **isnil@+0x15 / color@+0x14** node family:

1. isnil gate → throw `"invalid map/set<T> iterator"`.
2. Capture in-order successor (`FUN_00673070`).
3. Unlink + RB rebalance (Min `004e12a0` / Max `00421b70` / Lrot `004e22d0` / Rrot `006753b0`).
4. `operator_delete(node)` falls through (decomp false-noreturn).
5. If `size > 0` then `size--`; `*outIt = successor`.

Structural peer of dualed `Map_EraseRange_Isnil15`. **Distinct** from dualed isnil@+0x29 `Map_EraseNode` / `Map_EraseNode_B` and from dualed isnil15 `Map_EraseNode_IntKey` (`0x005d1df0`).

## Signature (byte-sealed)

```c
// __thiscall; ECX = map*; stack (Node** outIt, Node* z); RET 8 (C2 08 00)
void __thiscall Map_EraseNode_Isnil15(void* map, void** outIt, void* z);
// head @ map+4; size @ map+8; color @ node+0x14; isnil @ node+0x15
```

## Artifacts

- Raw (+ WQ9F-G re-verify): `docs/reconstruction/raw/aa_0051ce00_FUN_0051ce00.md`
- Annotated: `docs/reconstruction/raw/aa_0051ce00_FUN_0051ce00.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseNode_Isnil15.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051ce00.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051ce00_Map_EraseNode_Isnil15.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051ce00_Map_EraseNode_Isnil15.md`
- Alias record: `docs/reconstruction/functions/aa_0051ce00_FUN_0051ce00.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `Map_EraseRange_Isnil15` `0x0051d7c0` | partial loop; dualed WQ9E-J |
| Caller | `FUN_0051d940` | range-like erase parent (WQ9F-J OWN residual) |
| Caller | `FUN_0052c930` | map host erase site |
| Callee | successor / Min / Max / L-R rotates / `operator_delete` | see FUN record |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI + layout family | **Confirmed** |
| Structural name `Map_EraseNode_Isnil15` | **High** |
| Product/PDB English | Open |
| Runtime / bit-exact | Open |
