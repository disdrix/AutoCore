# Review B (skeptical / adversarial): `aa_005787a0` Skill_HB_RescheduleStatus_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005787a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-004) |
| **Counterpart** | `reviews/A_aa_005787a0_Skill_HB_RescheduleStatus_Inferred.md` |
| **VA** | `0x005787a0` only |
| **Verdict** | **accept-with-gaps** |

**Tools:** Live decompile + `disassemble_function` + `read_memory` + callers/xrefs + parent call-site context. **No** `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure reschedule wrapper (always AfterFire) | Fail path calls `vtbl+0x40` and returns without `00508350` | **Falsified** — gate can cancel |
| 2 | `__fastcall` with EDX `param_2` out | Assembly: only stack out-param; EDX never written as formal in | **Falsified** decompiler ABI |
| 3 | Status compare uses `this+0x74` (parent short field) | Bytes `CMP [ESI+0x2e]` / `MOV CX,[ESI+0x2e]` | **Falsified** — offset is **`+0x2e`** |
| 4 | Dynamic cast target is `CVOGCharacter` | RTTI push `0xaf8d0c` = `.?AVCVOGCreature@@` | **Falsified** — **Creature** |
| 5 | Fail status is 0 / continue | `MOV ECX,[af31e8]` value **0x10** | **Falsified** zero-status |
| 6 | Fail still reschedules period | No `CALL 00508350` on fail; direct `RET 4` | **Falsified** |
| 7 | This is heat/HP apply leaf | Callees are Resolve+Cast+vtbl+AfterFire only; no `00589bc0` etc. | **Falsified** merge |
| 8 | CVOGHBBase array overlay is real layout | sizeof base ~0x28; offsets to `+0x688` | **Confirmed mis-type** — absolute offs |
| 9 | Decompile diverges from raw | live ≡ raw CF; assembly only corrects ABI/overlays | **Falsified** diverge claim |
| 10 | Product name sealed without `_Inferred` | no plate/string for field English | **Open English** — keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 + EAX=out | **High** | broken HB status chain |
| `+0x2e` / creature `+0x12c` gate | **High** | wrong cancel threshold |
| Fail → stop + 0x10, no AfterFire | **High** | cascade still fires / stuck HB |
| Creature RTTI cast | **High** | wrong type path |
| `vtbl+0xb0` product verb | **Medium** | misnamed apply |
| Field English (`status` vs `level`) | **Open** | docs only |
| Runtime stacking | **Open** | shipping drift |

---

## 3. Cross-check against raw + assembly

```
raw / live decompile:
  if short@overlay != 0:
    ResolveObjectTarget(...); RTDynamicCast → Creature
    if null || creature[0x4b] < required:  // 0x4b*4 = 0x12c
      this.vtbl+0x40(); *out = DAT_00af31e8; return out
    creature.vtbl+0xb0(required)
  RescheduleAfterFire(this, out); return out

assembly:
  56 8B F1                 push esi; mov esi,ecx
  66 83 7E 2E 00           cmp word [esi+0x2e],0
  74 59                    jz reschedule
  ... CALL 004bae70 / CALL 004898a4 / ADD ESP,14
  66 39 88 2C 01 00 00     cmp [eax+0x12c],cx
  7C 1F                    jl fail
  FF 92 B0 00 00 00        call [edx+0xb0]
  E8 40 FB F8 FF           call RescheduleAfterFire @00508350
  C2 04 00                 ret 4
fail:
  FF 50 40                 call [eax+0x40]
  8B 0D E8 31 AF 00        mov ecx,[af31e8]
  89 08                    mov [eax],ecx
  C2 04 00                 ret 4
```

**No conflict** on owned CF. Decompiler phantom EDX / `__fastcall` rejected. Array overlay rejected.

---

## 4. Surviving contract for AutoCore

```csharp
// Skill_HB_RescheduleStatus_Inferred @ 0x005787a0
// __thiscall; ret 4; returns pOutStatus
uint Skill_HB_RescheduleStatus(SkillHB hb, out uint status)
{
  short required = hb.requiredAt2e; // product English open
  if (required != 0) {
    var obj = ResolveObjectTarget(hb.manager.reactionCtx, hb.tfid);
    var cre = DynamicCast<CVOGCreature>(obj);
    if (cre == null || cre.shortAt12c < required) {
      hb.VTable.StopOrCancel_vtbl40(); // exact name open
      status = 0x10; // DAT_00af31e8
      return status;
    }
    cre.VTable.ApplyOrSet_vtblB0(required);
  }
  CVOGHBBase_RescheduleAfterFire(hb, out status);
  return status;
}
```

Parent SharedOnHB: if `status == 0x10` skip effect cascade.

---

## 5. Residual risks

1. `vtbl+0xb0` / `vtbl+0x40` product names not dualled here.
2. `+0x2e` may be level, status-effect stacks, or another short metric — structural "status" is best-effort.
3. Alias relationship of 0x10 globals (`af31e8` vs `af4bd0` vs default period) not proven intentional beyond equal value.
4. No runtime hit confirmation in this dual.
5. Extra CALL xrefs at `00626bxx` not fully named (not OWN).

**Verdict:** **accept-with-gaps**
