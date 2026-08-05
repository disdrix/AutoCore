# Review A (reconstruction fidelity): `aa_00574910` ConvoyRoster_Unlock_NoOp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574910` |
| **VA** | `0x00574910` |
| **Body span** | `0x00574910` – `0x00574910` inclusive (**1** byte; exclusive end `0x00574911`) |
| **Canonical name** | `ConvoyRoster_Unlock_NoOp_Inferred` |
| **Prior / alias** | `FUN_00574910`; `Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_00574910` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00574910_ConvoyRoster_Unlock_NoOp_Inferred.md` |
| **System** | missions-progression / kill-XP convoy |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Empty leave-guard hook** after convoy kill-XP award loop. Single-byte `RET` (`c3`) no-op.

**Sole caller:** `CVOGCombat_OnDeathAwardKillXp` @ `0x004dac46`, after the 4-slot `FUN_00574760` + `CalculateAndAwardKillXP` loop that is preceded by `FUN_00574900` + `FUN_00574e60`. Mirror of the enter no-op — **unlock / leave sandwich** with empty body in this image.

Name **Inferred** from placement; machine fact is pure no-op.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Live decompile | Ghidra `0x00574910` | empty `return` ≡ raw |
| Live bytes | `read_memory` @ `0x00574910` | **`c3`** + `cc` pad; next code at `+0x10` is **other** bytes (`8d 81 a4 01…`) not this function |
| Live disasm | `disassemble_function` | single `RET` |
| Body meta | `get_function_by_address` | `00574910`–`00574910` |
| Callers / xrefs | live | **1** CALL — OnDeathAwardKillXp |
| Raw / annotated / clean | scaffold trio | ≡ empty |
| Pair lock | `aa_00574900` | sandwich peer |

**Not performed:** Launcher, runtime, rename, ledgers.

---

## 3. Machine proof

```text
0x00574910:  c3    ret
0x00574911–0x0057491f: cc padding
0x00574920+: 8d 81 a4 01 00 00 …  (neighbor code; NOT in this function body)
```

**Live decompile:**

```c
void FUN_00574910(void)
{
  return;
}
```

ABI: pure `ret`; zero stack args; ignores any thiscall ECX.

---

## 4. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| Body is pure `ret` | **High** | bytes + disasm + decompile |
| No stores / callees | **High** | empty |
| Exactly **1** caller | **High** | xrefs |
| Call site = convoy XP arm exit | **High** | OnDeathAward order |
| Distinct from Lock VA | **High** | different address |
| Neighbor `lea [ecx+0x1a4]` is **not** this body | **High** | function bounds + pad |
| Product “unlock” English | **Tentative / Inferred** | placement |
| Runtime | **Open** | policy |

---

## 5. Control flow / clean fidelity

| Stage | Match |
|---|---|
| Empty return only | **Yes** |

Clean scaffold correct.

---

## 6. Residual disposition

| Topic | Disposition |
|---|---|
| Machine no-op | **Sealed High** |
| Sole OnDeathAward exit CALL | **Sealed High** |
| Sandwich with `00574900` | **Sealed High** |
| Product unlock name | **Open / Inferred** |
| Neighbor code at +0x10 ownership | **Outside unit** (do not fold into this body) |

**Verdict:** **accept-with-gaps** — body + exclusive caller sealed; name open.
