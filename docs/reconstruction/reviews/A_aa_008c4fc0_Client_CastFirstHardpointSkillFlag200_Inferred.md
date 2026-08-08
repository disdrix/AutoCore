# Review A (reconstruction fidelity): `aa_008c4fc0` Client_CastFirstHardpointSkillFlag200_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c4fc0` |
| **VA** | `0x008c4fc0` |
| **Canonical name** | `Client_CastFirstHardpointSkillFlag200_Inferred` |
| **Review date** | `2026-08-04` (WQ8R-F dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` |
| **System** | skills-abilities / host hardpoint cast |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, callers/callees/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host-mode **first hardpoint skill** cast leaf: gate on `player+0x6b8`, TraversalLock-walk HB list on player or vehicle, RTTI-select first enabled `CVOGHBSkillBase`, and if skill flags `+0x614 & 0x200` call dualed `Client_CastSkillFromQuickBarSlot(skillId@+0x5fc)`.

WQ-008 residual: undualed callee of inventory/host UI path; also documented caller of sealed `Client_CastSkillFromQuickBarSlot`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x008c4fc0)` 2026-08-04 ≡ raw |
| Body bytes | `read_memory` 267 B; final `ADD ESP,8; RET`; cast `PUSH skillId; MOV ESI,0x00d1a840` |
| Callers | `get_function_callers` → sole `FUN_008c50f4` |
| Callees | TraversalLock, IterateNext, RTDynamicCast, LeaveCS, CastSkillFromQuickBarSlot |
| Parent context | decompile `FUN_008c50f4` — `+0x6b8 && !+0x6b9` → this; else mod-chip |
| Raw / annotated / clean / records | WQ8R-F trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw | **Confirmed** | 2026-08-04 |
| Sole caller `FUN_008c50f4` @ `0x008c510f` | **Confirmed** | xrefs |
| Gate `DAT_00d1b6d8` + `+0x6b8` | **Confirmed** | decomp + imm `0x6b8` |
| List host player vs vehicle (`+0x30c` / `+0x250`) | **Confirmed** | decomp |
| List at multi-inherit `+0xb4` | **Confirmed** | decomp pattern |
| `FUN_004294f0` = TraversalLock | **High** | registry + `"List Error! TraversalLock"` |
| `FUN_004022a0` = IterateNext | **High** | registry; ret 0 loop |
| Filter `+0x1c==1` + RTTI → `CVOGHBSkillBase` | **Confirmed** | decomp symbols |
| Enable `skillHb+0x140`; runtime `+0x24` | **Confirmed** | decomp |
| Flag test `skill+0x614 & 0x200` | **Confirmed** | `TEST …,0x200` + `JLE` |
| skillId `+0x5fc` → CastSkillFromQuickBarSlot | **Confirmed** | push + call |
| Client ESI = `&DAT_00d1a840` | **Confirmed** | `BE 40 A8 D1 00` |
| Name `_Inferred` (no product string) | **High** role / **Open** PDB | |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early gate player / `+0x6b8` | **Yes** |
| List host player vs vehicle | **Yes** |
| Lock → walk → unlock | **Yes** |
| First matching skill only | **Yes** |
| Flag 0x200 → cast with skillId | **Yes** |
| No invented network opcodes | **Yes** |

### Sealed CF sketch

```
Client_CastFirstHardpointSkillFlag200_Inferred():
  player = DAT_00d1b6d8
  if !player || !player[+0x6b8]: return
  if !player[+0x30c] || !player[+0x250]:
    list = *(MI(player)+0xb4)
  else:
    list = *(MI(vehicle)+0xb4)
  if !list: return
  List_TraversalLock(list)
  for each HB via List_IterateNext:
    if HB[+0x1c]==1 && dyn_cast SkillBase && SkillBase[+0x140]:
      skill = SkillBase+0x24; break
  unlock list if held
  if skill && (skill[+0x614] & 0x200):
    Client_CastSkillFromQuickBarSlot(client=&DAT_00d1a840, skill[+0x5fc])
```

---

## 5. Gaps

1. Product English for `+0x6b8`, `+0x30c`, list owner at `MI+0xb4`.
2. Semantic name of skill flag bit **0x200** (not aim `0x800`/`0x20`).
3. Why first-only (no multi-fire of all matching HBs).
4. PDB / retail symbol.
5. Runtime: case-8 / `0x9c40` UI → parent → this cast.

**Verdict:** **accept-with-gaps** — CF, list lock walk, RTTI filter, flag/cast ABI sealed; product labels residual.
