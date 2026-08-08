# Review A (reconstruction fidelity): `aa_004ce5c0` Character_TownInventoryFallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5c0` |
| **VA** | `0x004ce5c0`–`0x004ce5e3` (Ghidra body end; **36 B** / `0x24`) |
| **Canonical name** | `Character_TownInventoryFallback_Inferred` |
| **Ghidra name** | `FUN_004ce5c0` |
| **Prior / alias** | `Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0` (**retired** incomplete) |
| **Review date** | `2026-08-05` (MEGA-118 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` |
| **System** | inventory-transfer |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_callers`, `get_xrefs_to`, `get_assembly_context`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf mode-gate:** given mode-host + character, return whether mode flags allow locker / town-inventory fallback (`char+0xcbc` / inv type 3). Multi-caller (unequip free-slot miss + inventory-move mode 3 / free-slot miss) — not unequip-only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.md` (+ MEGA-118 append) |
| Annotated | `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_TownInventoryFallback_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004ce5c0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_004ce5c0_FUN_004ce5c0.md` |
| Function named | `docs/reconstruction/functions/aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live bytes | full body hex; three `c2 04 00`; `cc` pad → sibling `004ce5f0` |

---

## 3. Byte / ABI seal — **SEALED**

| Claim | Evidence | Conf |
|---|---|---|
| stack arg0 = character | `cmp dword [esp+4],0` | **High** |
| ECX = mode host | `cmp byte [ecx+0xf5]`; `cmp byte [ecx+0x7e]` | **High** |
| `ret 4` | three `c2 04 00` | **High** |
| Leaf (no CALL imm) | disasm + analyze callees `[]` | **High** |
| Decompile ≡ raw ≡ bytes | three-way | **High** |

```c
bool __thiscall Character_TownInventoryFallback_Inferred(int modeHost, int character);
// ret 4
```

Call-site corroboration:

| Site | ECX | push |
|---|---|---|
| `00862caa` | `DAT_00d1b644` | `DAT_00d1b6d8` |
| `00801351` | `client+0xe04` | `EAX = client+0xe98` |
| `00801654` | `client+0xe04` | `client+0xe98` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| null character → false | **Yes** |
| `+0xf5` short-circuit true | **Yes** |
| else `+0x7e != 0` | **Yes** |
| No invented stores / callees | **Yes** |

---

## 5. Caller roles (xref, not body)

| Site | Role note |
|---|---|
| `Client_SendInventoryUnequip` after free-slot fail | true → load `char+0xcbc`, retry `FUN_005714e0`; false → space toast |
| `FUN_008012f0` mode == 3 | gate then use locker grid `char+0xcbc` for place/swap |
| `FUN_008012f0` free-slot miss | true → retry free-slot; success stamps mode **3** |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Structural CF + offsets | **Yes** (sealed) |
| Multi-caller locker/`+0xcbc` role | **Yes** (caller CF) |
| Product/PDB symbol | **No** → **`_Inferred`** |
| Flag English / “town” product string | **No** (open gap) |

---

## 7. Gaps

1. Product/PDB symbol.
2. Mode-host flag English (`+0xf5` / `+0x7e`); relation `DAT_00d1b644` ↔ `client+0xe04`.
3. Product “town” vs layout “locker” for `+0xcbc`.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
