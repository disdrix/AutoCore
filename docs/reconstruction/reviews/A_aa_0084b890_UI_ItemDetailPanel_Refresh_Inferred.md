# Review A (reconstruction fidelity): `aa_0084b890` UI_ItemDetailPanel_Refresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0084b890` |
| **VA** | `0x0084b890` |
| **Body** | `0x0084b890`–`0x0084ca69` (**4569** / `0x11D9` bytes; `ret` / `c3`) |
| **Canonical name** | `UI_ItemDetailPanel_Refresh_Inferred` |
| **Ghidra name** | `FUN_0084b890` |
| **Prior alias** | `UI_overlay_broken` (string-weak) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W22-K) |
| **Counterpart** | `reviews/B_aa_0084b890_UI_ItemDetailPanel_Refresh_Inferred.md` |
| **System** | client UI / inventory item detail |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callees`, `get_function_xrefs` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **item detail / inspect panel virtual refresh**:

1. **Gate** on bound object at `this+0x518` (decomp `param_1[0x146]`).
2. Sample time (`FUN_007a69d0`), run `FUN_0084b210`, stamp overlay host `+0x488 = 1`.
3. Branch subtype short `== 8` → skill-mask overlay bind (`FUN_00519d20` + vfunc `+0x1a0` with `| 0xdf000000`) else clear bind; `FUN_0075bf40`.
4. Normal vs **broken overlay** texture `i_g_2d_overlay_broken.dds` (flags bit19 @ object `+0x17c` / `DAT_00d1791c`).
5. **Layout** child widgets from screen dims × widget metrics × `DAT_00aaa67c` / `DAT_00aaa678`.
6. Optional **percent** line (`%.01f%% %s`) clamped to `100.0` (`DAT_00aaa7ac`).
7. Name lines (`%s: %s`), stacked children, **`UI_BuildItemTooltipStats`**.
8. Optional **angle gauges** via `Math_AcosClamped` × `DAT_00aaa99c` (≈`360/π` ≈114.59).
9. COID pair match in player table `@ DAT_00d1b6d8+0x5a0` (8 slots) may set `DAT_00d1791c`.
10. Footer type-4 vs `FUN_005140d0` label; final show/hide.

**Not** a network handler. **Not** freelist/hash. Pure client UI.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `raw/aa_0084b890_FUN_0084b890.md` | W22-K live append ≡ decompile |
| Annotated | `raw/aa_0084b890_FUN_0084b890.annotated.md` | stage map sealed |
| Clean scaffold | `reconstructed-exact/FUN_0084b890.cpp` | full decomp surface |
| Named clean | `reconstructed-exact/UI_ItemDetailPanel_Refresh_Inferred.cpp` | stage CF |
| Function record | `functions/aa_0084b890_FUN_0084b890.md` | dual sealed |
| Live decompile | Ghidra `0x0084b890` | ≡ raw (~996 lines) |
| Entry bytes | `read_memory` @ `0084b890` len 48 | prologue + gate |
| Epilogue | `read_memory` @ `0084ca50` | `ret` |
| Constants | `read_memory` DAT_00aaa678/67c/7ac/99c | float sealed |
| Xrefs | DATA `0x00a697e4` only | vtbl |
| Related dual | `A_aa_00847ad0_UI_BuildItemTooltipStats` | callee |
| Related dual | `A_aa_0040d0a0_Math_AcosClamped` | gauge |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range / size 4569 | **Confirmed** | `get_function_by_address` |
| `this` in ECX → EBP | **Confirmed** | `8B E9` after pushes |
| Gate `this+0x518 == 0` early out | **Confirmed** | `83 BD 18 05 00 00 00` + long jz |
| Frame `sub esp,0x140` + align | **Confirmed** | prologue |
| Vtbl-only dispatch | **Confirmed** | single DATA xref |
| Strings broken DDS / percent / name | **Confirmed** | decompile |
| `UI_BuildItemTooltipStats` call | **Confirmed** | callees list + body |
| X scale ≈0.000625, Y ≈0.000833 | **Confirmed** | `read_memory` floats |
| Percent clamp 100.0 | **Confirmed** | `DAT_00aaa7ac` |
| Deg scale ≈114.5916 | **Confirmed** | `DAT_00aaa99c` (=360/π); `acos` callee; product domain residual |
| COID walk 8 × 8-byte @ +0x5a0 | **Confirmed** | decompile loop |
| Child widget product names | **Tentative** | offsets only |
| Panel product class / vtbl RTTI | **Open** | not sealed |
| Runtime path that binds +0x518 | **Open** | |
| Bit-exact full body | **Open** | large; stage seal only |

---

## 4. Control flow: clean ≡ raw ≡ live (stages)

| Stage | Match |
|---|---|
| Gate null object | **Yes** |
| Time + `FUN_0084b210` + overlay flag | **Yes** |
| Subtype-8 mask vs zero bind | **Yes** |
| Broken vs normal overlay | **Yes** |
| Screen-scaled layout | **Yes** |
| Optional percent + name text | **Yes** |
| Child stack / tooltip stats | **Yes** |
| Gauges acos×deg | **Yes** |
| COID table flag | **Yes** |
| Footer + return | **Yes** |

### Entry / gate (machine)

```
push ebp; mov ebp,esp; and esp,-8; sub esp,0x140
push ebx,ebp,esi,edi; mov ebp, ecx          ; this
cmp dword [ebp+0x518], 0
jz  end                                      ; +0x11B3 bytes later
call FUN_007a69d0
```

### Float constants (sealed)

| DAT | Bits | Float |
|---|---|---|
| `00aaa678` | `3a5a740e` | ≈0.00083333 |
| `00aaa67c` | `3a23d70a` | ≈0.00062500 |
| `00aaa7ac` | `42c80000` | 100.0 |
| `00aaa99c` | `42e52ee2` | ≈114.59156 |

---

## 5. Layout (panel fields this unit gates/uses)

| Off | Role |
|---|---|
| `+0x518` | bound `GameObject*` (required) |
| `+0x528` | char flag (footer branch with `DAT_00d1791c`) |
| `+0x52c`… | child `UiWidget*` cluster (overlay/text/stack/gauges) |

Object: `+0x160/+0x164` COID; `+0x17c` bit19; type chain via `+0xa8`.

---

## 6. Callers / callees

**Callers:** virtual only (`0x00a697e4`).

**Notable callees:** see function record — tooltip builder, acos, locale, sprintf, panel helpers `0084b210` / `00845880` / `00845b40` / `00845af0` / `00847240`.

---

## 7. Gaps / open

1. Product panel class name / full RTTI for vtbl `0x00a697e0` region.
2. English names for every child slot and every vfunc ordinal.
3. Skill-mask constant `0xdf000000` product meaning.
4. Which UI open path installs this vtbl and writes `+0x518`.
5. Runtime / differential / bit-exact of full 4.5KB body.

**Verdict:** **accept-with-gaps** — ABI, gate, strings, constants, major stages, and tooltip/gauge hooks sealed; residual is product naming and exhaustive vfunc catalog.
