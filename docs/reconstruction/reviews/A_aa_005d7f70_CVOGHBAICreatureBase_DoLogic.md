# Review A (reconstruction fidelity): `aa_005d7f70` CVOGHBAICreatureBase_DoLogic

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7f70` |
| **VA** | `0x005d7f70`–`0x005d8328` |
| **Canonical name** | `CVOGHBAICreatureBase_DoLogic` |
| **Ghidra name** | `FUN_005d7f70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-J) |
| **Counterpart** | `reviews/B_aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md` |
| **System** | npc-ai / HBAI / creature |
| **Evidence pass** | Live `decompile_function` + `read_memory` + DATA vtbl xref; twin `CVOGHBAIDriver_DoLogic`; sibling `DecideHeading` product string |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-tick **ground creature** HBAI combat/logic: resolve AI profile row by def float key, then run state machine on **owner+0x26c** (idle / engage / combat) with skill-set casts, slot timer, leash helpers, HP/RNG gates, and `DoCreaturePursue`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d7f70_FUN_005d7f70.md` (+ W25-J append) |
| Annotated | `docs/reconstruction/raw/aa_005d7f70_FUN_005d7f70.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoLogic.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_005d7f70.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md` |
| Twin | `reconstructed-exact/CVOGHBAIDriver_DoLogic.cpp` (`0x005d7750`, plate string) |
| Sibling | `CVOGHBAICreatureBase_DecideHeading` @ `0x005d0840` (vtbl neighbor) |

---

## 3. Signature

```c
// Ghidra: void __fastcall FUN_005d7f70(int *param_1)
// Bytes: mov esi,ecx … add esp,0xC; ret
void __thiscall CVOGHBAICreatureBase_DoLogic(CVOGHBAICreatureBase *this);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| bare ret / void | tail `C3` | **High** |
| Class CVOGHBAICreatureBase | vtbl co-slot with DecideHeading string | **High** |
| Method name DoLogic | structural twin of Driver::DoLogic; **no** in-body plate | **Probable** |

---

## 4. Control flow (sealed)

1. Build float key from owner MI → def `+0x4DC`; `FUN_00540890` + `FUN_004cbd50` lower_bound; **return if end iterator**.
2. Clear owner `+0x279`.
3. **State 0 (idle):** cast set 0; slot-timer → vtbl `+0x1C`; target present → state 2; path helpers / face target copy / vtbl `+0x4C`.
4. **State ≠0,≠1 (combat):** cast set 2; if timer ready, HP-ratio RNG vs profile `[7..11]` (flee `FUN_00638cd0`, demote to engage); else clear state if no target; pursue via `FUN_005cf560` (`DoCreaturePursue`).
5. **State 1 (engage):** stamp timer; cast set 1; timeout or HP≥profile[6] → state 0/2; else path helpers.

| Stage | Match | Conf |
|---|---|---|
| Profile lower_bound early-out | **Yes** | **High** |
| owner+0x26c ternary | **Yes** | **High** |
| Skill sets 0/1/2 | **Yes** | **High** |
| No FireWeapons tail (unlike Driver) | **Yes** | **High** |
| DoCreaturePursue in combat | **Yes** (`FUN_005cf560`) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x005d7f70` | `83 EC 0C 53 55 56 8B F1` | prolog; ESI=this |
| owner load | `8B 46 64` | `mov eax,[esi+0x64]` (=`this[0x19]`) |
| host ECX | `8B 0D FC 41 B0 00` | `mov ecx,DAT_00b041fc` before profile call |
| tail | `5F 5E 5D 5B 83 C4 0C C3` | bare ret |
| `0x00aaa638` | `80 00 80 37` | ≈1/65536 |
| `0x00aaa5dc` | `00 00 80 4F` | 2^32 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Notes |
|---|---|
| **Caller** | DATA only — vtbl `0x009db19c` (virtual dispatch) |
| **Callees** | `FUN_00540890`, `FUN_004cbd50`, `NPC_TryCastSkillFromSet`, `AI_CheckSlotTimerReady`, `CVOGReaction_RandomUnitScalar`, `FUN_005cedf0`, `FUN_005cc980`, `FUN_005cebd0`, `FUN_005cc450`, `FUN_005ccbd0`, `FUN_0053e0b0`, `FUN_00404e00`, `FUN_00638cd0`, `FUN_005cf560` (DoCreaturePursue), vtbl `+0x1C/+0x2C/+0x4C`, target host `+0x1A0/+0x1AC/+0x1B0` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI thiscall void + state machine CF | **High** |
| Class CVOGHBAICreatureBase | **High** (vtbl sibling string) |
| Method English `DoLogic` | **Probable** (Driver twin; no local plate) |
| Profile field English `[5]..[11]` | **Partial / Inferred** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product plate string for this method (absent in body).
2. Full AI profile struct English for map payload.
3. Exact roles of `FUN_005cedf0` / `005cc980` / `005cebd0` / `005cc450` / `005ccbd0` (shared path helpers — out of sole ownership).
4. `unaff_EDI` in decomp of `AI_CheckSlotTimerReady` is decompiler noise; sealed sibling takes one stack slot index.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, class, and CF sealed; method English Probable; profile field names open.
