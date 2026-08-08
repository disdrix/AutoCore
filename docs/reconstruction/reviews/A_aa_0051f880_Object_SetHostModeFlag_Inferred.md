# Review A (reconstruction fidelity): `aa_0051f880` Object_SetHostModeFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f880` |
| **VA** | `0x0051f880`–`0x0051f88c` (13 B; pad `CC` after) |
| **Canonical name** | `Object_SetHostModeFlag_Inferred` (Ghidra `FUN_0051f880`) |
| **Review date** | `2026-08-04` (OWN-ONLY dual A — WQ9F-I) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0051f880_Object_SetHostModeFlag_Inferred.md` |
| **System** | object / character status (skills-abilities writer) |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

**Leaf host-mode flag setter.** Write the single stack byte into `this+0x6b8` and return. No branches, no callees, no validation. Twin of `Object_SetEnhancedStateFlag_Inferred` (`+0x6b9`).

```c
// __thiscall  ECX = this (character/object)
// stack: uint8_t fHostMode
// ret 4; void
void Object_SetHostModeFlag_Inferred(void *this, uint8_t fHostMode);
```

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Live decompile | Ghidra @ `0x0051f880` | **≡** raw |
| Live bytes | `read_memory` 16 B | full leaf + pad |
| Live disasm | `disassemble_function` | 3 ins |
| Callers | `analyze_function_complete` | 2 code sites |
| Twin | `aa_0051f890` dual | same ABI template @ `+0x6b9` |
| FireTail dual | `aa_00578b30` | push **1** sealed |
| OnEnd dual | `aa_00578ce0` | push **0** sealed |
| Raw / annotated / clean | trio under `docs/reconstruction/` | refined |

**Not performed:** Launcher, runtime golden, parent ledgers.

---

## 3. Signature / bytes (image-sealed)

```
0051f880  8A 44 24 04           mov al, [esp+4]
0051f884  88 81 B8 06 00 00     mov [ecx+0x6b8], al
0051f88a  C2 04 00              ret 4
0051f88d  CC…                   int3 pad
```

Hex body: `8a4424048881b8060000c20400`

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | store via `[ecx+0x6b8]` | **High** |
| One stack byte | `mov al,[esp+4]` | **High** |
| Epilogue `ret 4` | `C2 04 00` | **High** |
| Offset `+0x6b8` | imm `B8 06 00 00` | **High** |
| Void | bare ret after store | **High** |
| Host-mode role | CastFirstHardpoint / QuickBar readers + Fire/OnEnd polarity | **High** (role) |
| Product method spelling | structural only | **Inferred** |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Load stack byte | **Yes** |
| Store `this+0x6b8` | **Yes** |
| `ret 4` | **Yes** |
| No branches / callees | **Yes** |

---

## 5. Call sites

| Site | Container | Arg | Role |
|---|---|---|---|
| `0x00578c78` | `Skill_HB_FireTail_FxTargetAndPeriodStamp` | `1` | set on target char after `vtbl+0x210(0)` |
| `0x00578dd1` | `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` | `0` | clear inverse |

Both sites: `TEST EAX,EAX` / `JZ` skip; `PUSH imm` / `MOV ECX,EAX` / `CALL 0x0051f880`.

---

## 6. Naming

| Name | Status |
|---|---|
| `Object_SetHostModeFlag_Inferred` | **Structural inferred** (offset twin of enhanced + reader "host-mode") |
| `FUN_0051f880` | scaffold alias |
| Prior `Named_CalleeOf_Skill_…frequency…` | **reject** as product |
| PDB product name | **Open** |

---

## 7. Gaps (acceptable)

1. Product/PDB English for method name.
2. Full writer catalog beyond two static CALL sites.
3. Neighboring status bytes `+0x6ba/+0x6bb` full inventory.
4. Runtime / bit-exact / differential — open (Terminal false).

**Verdict:** **accept-with-gaps** — 13-byte CF + ABI + offset fully sealed; host-mode English remains `_Inferred`.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| Bytes seal store + ret 4 | **Pass** |
| Twin enhanced leaf consistency | **Pass** |
| Fire/OnEnd polarity documented | **Pass** |
| Clean uses meaningful names | **Pass** |
