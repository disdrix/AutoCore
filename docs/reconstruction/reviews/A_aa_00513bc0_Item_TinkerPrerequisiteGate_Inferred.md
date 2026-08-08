# Review A (reconstruction fidelity): `aa_00513bc0` Item_TinkerPrerequisiteGate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513bc0` |
| **VA** | `0x00513bc0` |
| **Body** | `0x00513bc0`–`0x00513c06` inclusive (**71 B** / `0x47`) |
| **Canonical name** | `Item_TinkerPrerequisiteGate_Inferred` (Ghidra `FUN_00513bc0`; **Inferred**) |
| **Prior names** | `FUN_00513bc0`; scaffold `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00513bc0` |
| **Review date** | `2026-08-05` (MEGA-104 OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00513bc0_Item_TinkerPrerequisiteGate_Inferred.md` |
| **System** | inventory-transfer / tinker kit validation |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Boolean type-compatibility prerequisite gate** for tinker-kit use validation.

Returns 1 when the candidate item’s type matches the kit’s host type, or when the candidate presents remapped type-6 codes `0x44`/`0x46` and the kit’s def subtype short is 10/11 respectively. Returns 0 on null candidate or mismatch.

Sole static caller `FUN_00513c10` treats fail as status code **3** (prereq fail) before skill/level/charge checks.

Not a skill check, not a charge consumer, not the full tinker validator.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513bc0_FUN_00513bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513bc0_FUN_00513bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_TinkerPrerequisiteGate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513bc0.cpp` |
| Function records | `aa_00513bc0_FUN_00513bc0.md` + named |
| Live decompile | Ghidra `0x00513bc0` (2026-08-05) **≡** raw |
| Machine | `disassemble_function` + `read_memory` 128 B |
| Callers | `get_function_callers` / `get_xrefs_to` → `FUN_00513c10` only |
| Related (context) | `FUN_00513c10` parent; `FUN_00509b10` type-6 remap 10→0x44 / 11→0x46; `FUN_00513d10` subtype window |

---

## 3. Byte / ABI seal

```text
00513bc0  8B 44 24 04          mov  eax, [esp+4]     ; candidate
00513bc4  85 C0                test eax, eax
00513bc6  74 3A                jz   fail
00513bc8  8B 89 A8 00 00 00    mov  ecx, [ecx+0xa8]  ; kit host
00513bce  8B 80 B4 00 00 00    mov  eax, [eax+0xb4]  ; cand type
00513bd4  3B 41 38             cmp  eax, [ecx+0x38]  ; kit type
00513bd7  74 17                jz   pass
00513bd9  83 E8 44             sub  eax, 0x44
00513bdc  74 17                jz   check_sub_10
00513bde  83 E8 02             sub  eax, 2           ; → 0x46?
00513be1  75 1F                jnz  fail
          ... cmp word [def+0x3f4], 0x0B ...
00513bf0  B0 01                mov  al, 1
00513bf2  C2 04 00             ret  4
          ... cmp word [def+0x3f4], 0x0A ...
00513c02  32 C0                xor  al, al
00513c04  C2 04 00             ret  4
00513c07  CC…                  pad to FUN_00513c10
```

| Claim | Confidence | Evidence |
|---|---|---|
| Body 71 B inclusive end `0x00513c06` | **High** | last `RET 4` = `C2 04 00` |
| `__thiscall` kit + stack candidate; **`RET 4`** | **High** | ECX host load; `[esp+4]`; `C2 04 00` ×2 |
| Bool in AL | **High** | `B0 01` / `32 C0`; parent `TEST AL,AL` |
| Leaf (no callees) | **High** | analyze + disasm |
| Direct type match `cand+0xb4` vs `host+0x38` | **High** | |
| Specials `0x44`↔subtype 10, `0x46`↔11 | **High** | immediates in cmp |
| Sole caller `FUN_00513c10` @ `0x00513c36` | **High** | 1 UNCONDITIONAL_CALL |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null candidate → fail | **Yes** |
| Direct type equality → pass | **Yes** |
| Type 0x44 + kit subtype 10 → pass | **Yes** |
| Type 0x46 + kit subtype 11 → pass | **Yes** |
| Else → fail | **Yes** |
| Decompiler CONCAT/`& 0xffffff00` = AL bool packaging | **Yes** |

---

## 5. Caller usage (context)

| Caller | Role |
|---|---|
| `FUN_00513c10` | Residual tinker-kit validator; fail → return `3` |
| (grandparent) `FUN_0085ce20` / `FUN_0085f660` | UI / apply paths seeded by tinkering skill string |

---

## 6. Gaps

1. Product/PDB English — open (`_Inferred`).
2. Product names for type ids `0x44` / `0x46` and for `+0xb4` vs `host+0x38`.
3. Parent `FUN_00513c10` dual residual (MEGA partition; not OWN).
4. Runtime / differential golden — open.

**Verdict:** CF/ABI/offsets **High**. Product type lexicon residual. **accept-with-gaps.**
