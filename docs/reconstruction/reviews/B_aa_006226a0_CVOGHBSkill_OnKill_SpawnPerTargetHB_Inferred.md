# Review B (skeptical / adversarial): `aa_006226a0` CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006226a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-020) |
| **Counterpart** | `reviews/A_aa_006226a0_CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + xrefs. **No** `disassemble_bytes`. Own VA `0x006226a0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function **is** a subclass ctor (partition parent list) | Body is table loop + Enqueue/Start | **Falsified** as ctor — it *calls* base ctor |
| 2 | Free / non-virtual helper | sole xref DATA @ vtbl+0x2c | **Falsified** — virtual install |
| 3 | thiscall with used `this` | ECX never read as incoming this | **Partial** — ABI thiscall surface, body ignores ECX |
| 4 | `ret 4` / few args | epilogue `C2 18 00` | **Falsified** — **6 stack args** |
| 5 | Resolve is free function (decompiler) | asm `MOV ECX,[EBP+0xe4e8]` + thiscall callee | **Falsified** decompiler drop |
| 6 | Always starts HB | owner-null path dtor(1) without Enqueue | **Falsified** conditional |
| 7 | Returns 0 on resolve miss | miss only increments index; only exit is return 1 | **Falsified** |
| 8 | Class is generic SkillBase | RTTI `.?AVCVOGHBSkill_OnKill@@` | **Falsified** |
| 9 | Live decomp diverges CF from raw | cosmetic names only | **Falsified** as CF break |
| 10 | Product method name proven | no method string | **Open English** — `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 0x18 / six args / return 1 | **High** | stack corruption |
| OnKill RTTI + vtbl+0x2c | **Confirmed** | wrong class wiring |
| Target entry 0x10 / sentinel | **High** | infinite loop / skip |
| Resolve thiscall world+0xe4e8 | **High** | null resolve |
| HB 0x6c0 + base ctor + vtbl | **High** | wrong action type |
| Enqueue world+0xe4ec + Start | **High** | skills never fire |
| Method product English | **Open** | doc-only |
| Runtime / bit-exact | **Open** | shipping image |

---

## 3. Cross-check against raw + bytes

```
raw / live CF:
  index=0; loop
  entry = table + index*0x10
  if idLo==-1 && idHi==-1 && type==0: return 1
  resolve(type,idLo,idHi) via world+0xe4e8
  if hit: new 0x6c0; CVOGHBSkillBase_ctor(...); vtbl=OnKill
         if owner: Enqueue(world+0xe4ec)+Start else dtor(1)
  index++

bytes / asm:
  prolog SEH 6A FF 68 7B 89 9A 00
  PUSH 0x6c0 (C0 06 00 00)
  CALL 0x005788d0; MOV [ESI], 0x009d16e4
  MOV ECX,[EBP+0xe4ec]; Enqueue; Start
  epilogue B8 01 00 00 00 … C2 18 00
  DATA 009d1710 = A0 26 62 00
  type_info 00af1dc8 = ".?AVCVOGHBSkill_OnKill@@"
```

**No conflict** on owned CF. Decompiler CONCAT31 / missing Resolve this = presentation only.

---

## 4. Surviving contract for AutoCore

```csharp
// CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred @ 0x006226a0
// retail: virtual vtbl+0x2c; 6 stack args; ret 0x18; return 1 at sentinel
// class RTTI Confirmed CVOGHBSkill_OnKill

uint SpawnPerTargetHB(OnKillHb selfIgnored, Object source, SkillBlob skill,
                      WorldCtx world, TargetEntry* table, uint* tfid16, uint arg7)
{
  // for each table entry until (-1,-1,0):
  //   resolve via world.reaction(+0xe4e8)
  //   new HB 0x6c0; SkillBase_ctor; vtbl=OnKill; Enqueue/Start or delete
  // return 1
}
```

---

## 5. Residual risks

1. Unbounded loop if table lacks sentinel — must preserve retail table contract.
2. Ignoring ECX may hide future duals that pass HB-local state only in `this` (not observed here).
3. No live OnKill cast capture in this dual. Terminal **false**.
