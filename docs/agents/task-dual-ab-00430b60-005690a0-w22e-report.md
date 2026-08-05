# Dual A/B report — W22-E OWN-ONLY (`0x00430b60`, `0x005690a0`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00430b60`, `0x005690a0`. Dual A/B + artifacts.  
**Agent:** W22-E OWN-ONLY  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Verdict |
|------|---------|
| `aa_00430b60` StdMap_StringKey_InsertNodeAndRebalance | **accept-with-gaps** — **EDI map / ECX where / ret 0x0C**, node **0x30** color **+0x2C**, always-insert + RB sealed; product name open |
| `aa_005690a0` StdMap_IntKey_InsertNodeAndRebalance_Inferred | **accept-with-gaps** — **thiscall + ret 0x10**, node **0x4C** / 15 dwords / color **+0x48**, always-insert + RB sealed; full value typedef open |

---

## Sealed facts — `aa_00430b60` (0x00430b60)

1. **ABI:** custom — **map in EDI**, **where in ECX**, stack `outIt*` / `addLeft` / `valuePair*`, **`ret 0x0C`**. Not ECX-thiscall for the map.

2. **Body:** `0x00430b60`–`0x00430cdd` (**381 B**); epilogue `C2 0C 00`.

3. **Layout:** map head@+4, size@+8; node **0x30** (`FUN_0042a890`); string key @+0x0C; mapped u32 @+0x28; color @+0x2C; isnil @+0x2D.

4. **Algorithm:** max-size guard (`size > 0x7FFFFFD` → `"map/set<T> too long"` via `FUN_00401a40` + `DAT_00acc388`); always construct red node; size++; link empty/left/right + extrema; RB fixup; root black; `*outIt = new`.

5. **Rotates:** `FUN_0044e010` left / `FUN_0042a840` right (isnil +0x2D).

6. **Decompiler hazard sealed:** `unaff_EDI` is the real map; third stack formal (value) required by `ret 0x0C` + node ctor ECX load.

7. **Name:** `StdMap_StringKey_InsertNodeAndRebalance` — role-sealed **INFERRED** from plate + parent `StdMap_StringKey_InsertOrFind`. Ghidra: `FUN_00430b60`.

8. **Callers:** `FUN_004309c0` (×2), `FUN_004303c0` (×6), `FUN_0044d9f0` (×2).

### Gaps (`00430b60`)

1. Product/PDB English symbol.  
2. Mapped-value domain beyond u32 @ +0x28.  
3. Runtime / bit-exact / differential — open.

---

## Sealed facts — `aa_005690a0` (0x005690a0)

1. **ABI:** `__thiscall` — **map in ECX**, stack `outIt*` / `addLeft` / `where*` / `value*`, **`ret 0x10`**.

2. **Body:** `0x005690a0`–`0x0056928a` (**490 B**); epilogue `C2 10 00`.

3. **Layout:** head@+4, size@+8; node **0x4C** (`FUN_00568f60`); **15 dwords** @+0x0C; color @+0x48; isnil @+0x49.

4. **Algorithm:** max-size (`size > 0x4444442` → plate throw, inlined exception path); always construct red node; size++; link; RB fixup; root black; `*outIt = new`.

5. **Rotates:** `FUN_00568b70` L / `FUN_005681a0` R; one grandparent L-rotate **inlined** (same family as sealed `aa_00538ea0`).

6. **Distinct from staging insert:** staging `00538ea0` is **0x50** / 14 dwords; this VA is **0x4C** / 15 dwords (shared rotate helpers only).

7. **Name:** `StdMap_IntKey_InsertNodeAndRebalance_Inferred` — role-sealed **INFERRED** (int key @ +0x0C from parent duals). Ghidra: `FUN_005690a0`.

8. **Callers:** `FUN_00569320` (×2), `FUN_00569560` (×8), `FUN_005692b0` (×1).

### Gaps (`005690a0`)

1. Product/PDB English / full 15-dword value typedef.  
2. Runtime / bit-exact / differential — open.  
3. Inlined L-rotate is codegen, not semantic gap.

---

## Files

### `aa_00430b60`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00430b60_StdMap_StringKey_InsertNodeAndRebalance.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00430b60_StdMap_StringKey_InsertNodeAndRebalance.md` |
| Function record | `docs/reconstruction/functions/aa_00430b60_FUN_00430b60.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_StringKey_InsertNodeAndRebalance.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00430b60.cpp` |
| Raw (authoritative + W22-E re-verify) | `docs/reconstruction/raw/aa_00430b60_FUN_00430b60.md` |
| Annotated | `docs/reconstruction/raw/aa_00430b60_FUN_00430b60.annotated.md` |

### `aa_005690a0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005690a0_StdMap_IntKey_InsertNodeAndRebalance_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005690a0_StdMap_IntKey_InsertNodeAndRebalance_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005690a0_FUN_005690a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_IntKey_InsertNodeAndRebalance_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_005690a0.cpp` |
| Raw (authoritative + W22-E re-verify) | `docs/reconstruction/raw/aa_005690a0_FUN_005690a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005690a0_FUN_005690a0.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00430b60-005690a0-w22e-report.md` |

---

## Port notes (client containers only)

- Both units are pure STL tree mutators: useful for understanding client map growth / throw paths, not sector gameplay rules.
- String-key insert feeds `StdMap_StringKey_InsertOrFind` families; int-key insert feeds sealed insert-or-find / insert-with-hint duals already in the tree.
- Server ports should continue using managed containers; these seals document **retail client** max-size thresholds and node footprints only.
