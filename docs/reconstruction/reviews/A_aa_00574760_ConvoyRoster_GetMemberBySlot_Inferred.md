# Review A (reconstruction fidelity): `aa_00574760` ConvoyRoster_GetMemberBySlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574760` |
| **VA** | `0x00574760` |
| **Body span** | `0x00574760` – `0x0057477e` inclusive (exclusive end `0x0057477f`) |
| **Canonical name** | `ConvoyRoster_GetMemberBySlot_Inferred` |
| **Prior / alias** | `FUN_00574760`; `Named_CalleeOf_Client_Input_PollBoundActions_00574760` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00574760_ConvoyRoster_GetMemberBySlot_Inferred.md` |
| **System** | convoy / missions-progression (cross-used) |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bounded convoy-roster slot load.** `__thiscall` with one stack `int` slot index:

* If `0 ≤ index ≤ 3` (`-1 < index && index < 4`), return the **dword** at `this + (index + 0x1a) * 0x10` (= `this + 0x1a0 + index * 0x10`).
* Otherwise return **0**.

Callers treat the result as a **character / convoy-member object pointer** (null = empty slot). Product English name is **Inferred** (no string/RTTI on this VA); role sealed by layout + call graph (slots 0..3, same `+0x1a0` base as `FUN_00574e60` walker, gated by `char+0xcb0` convoy ptr at many sites).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Live decompile | Ghidra `decompile_function` / `batch_decompile` `0x00574760` | **≡ raw** |
| Live bytes | `read_memory` @ `0x00574760` len 32 | `8b442404…c20400 33c0 c20400 cc` |
| Live disasm | `disassemble_function` | 11 ins; dual `ret 4` exits |
| Callers | `get_function_callers` | **16** functions |
| Xrefs | `get_xrefs_to` | **30** unconditional CALLs |
| Raw | `raw/aa_00574760_FUN_00574760.md` | Body frozen ≡ live |
| Annotated | `raw/aa_00574760_FUN_00574760.annotated.md` | Scaffold |
| Clean | `reconstructed-exact/FUN_00574760.cpp` | CF match |
| Sibling count | `aa_00574e60` walks same `+0x1a0` stride `0x10` ×4 | Layout cross-check |
| Parent XP | `CVOGCombat_OnDeathAwardKillXp` `0x004da630` | Convoy award loop |
| Parent input | `Client_Input_PollBoundActions` `0x00925d60` | Slots 0..3 when `+0xcb0` |

**Not performed:** Launcher, runtime golden, Ghidra product rename, ledger updates.

---

## 3. Machine proof

**Live decompile (2026-07-29):**

```c
undefined4 __thiscall FUN_00574760(int param_1, int param_2)
{
  if ((-1 < param_2) && (param_2 < 4)) {
    return *(undefined4 *)((param_2 + 0x1a) * 0x10 + param_1);
  }
  return 0;
}
```

**Disassembly:**

```text
00574760  mov  eax, [esp+4]      ; index (stack arg)
00574764  cmp  eax, -1
00574767  jle  0057477a          ; → 0
00574769  cmp  eax, 4
0057476c  jge  0057477a          ; → 0
0057476e  add  eax, 0x1a
00574771  shl  eax, 4            ; * 0x10
00574774  mov  eax, [eax+ecx]    ; thiscall ECX = roster
00574777  ret  4
0057477a  xor  eax, eax
0057477c  ret  4
```

**ABI (High):** MSVC `__thiscall`, **one** stack dword, `ret 4` (not pure `c3`). ECX = roster object; body does not re-load ECX from globals.

**Offset algebra (High):** `(index + 0x1a) * 0x10` = `0x1a0 + index*0x10` for index∈{0,1,2,3}.

---

## 4. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| CF: bounds then load else 0 | **High** | decompile ≡ disasm ≡ raw ≡ clean |
| Slot base `this+0x1a0`, stride `0x10`, capacity **4** | **High** | math + sibling `FUN_00574e60` loop |
| Returns dword (pointer-shaped at call sites) | **High** | `mov eax,[eax+ecx]`; null checks at callers |
| Invalid index → 0 | **High** | `xor eax,eax; ret 4` |
| `__thiscall` + `ret 4` | **High** | disasm |
| `this` is convoy roster (not always killer char) | **High** structure / **Probable** type name | Callers gate on `char+0xcb0`; decompiler often hides ECX setup |
| Used as convoy member object | **High** | XP loop / PollBoundActions vtbl on result |
| Product English name | **Low / Inferred** | No string/RTTI |
| Runtime / bit-exact | **Open** | policy |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `index > -1 && index < 4` | **Yes** |
| Load `*(this + (index+0x1a)*0x10)` | **Yes** |
| Else return 0 | **Yes** |
| No callees | **Yes** |

### Clean fidelity

| Aspect | Fidelity |
|---|---|
| CF / return | **Good** (scaffold) |
| Named `this` / field | **Gap** — still `param_1` / raw offsets |
| Semantic plate | **Gap** — auto scaffold |

---

## 6. Call graph (sealed static)

**Sample high-value callers (not exhaustive of 30 xrefs):**

| Caller | VA | Role |
|---|---|---|
| `CVOGCombat_OnDeathAwardKillXp` | `0x004da630` | Convoy assist + XP award loops |
| `Client_Input_PollBoundActions` | `0x00925d60` | Bound actions for convoy slots 0..3 |
| `CVOGHBMissionPatrol_Tick` | `0x00650f90` | HB patrol |
| `CVOGObjectiveRequirement_Collect_Action` | `0x00611f20` | Collect convoy GiveItem path |
| `FUN_00523d50`, `FUN_00575870`, `FUN_0057ade0`, UI/skill family | various | Roster member resolve |

---

## 7. Residual disposition

| Topic | Disposition |
|---|---|
| Body CF + offset formula | **Sealed High** |
| Capacity 4 / stride 0x10 / base +0x1a0 | **Sealed High** |
| ABI thiscall `ret 4` | **Sealed High** |
| Result = member object pointer | **Sealed High** at use sites |
| Exact C++ type of `this` | **Probable** convoy roster (`char+0xcb0`) |
| Slot struct fields beyond first dword | **Open** (only dword[0] read here) |
| Product name | **Open / Inferred** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — machine body and slot math sealed; type/name open.
