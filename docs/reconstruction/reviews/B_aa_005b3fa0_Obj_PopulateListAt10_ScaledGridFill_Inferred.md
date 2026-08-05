# Review B (skeptical / adversarial): `aa_005b3fa0` Obj_PopulateListAt10_ScaledGridFill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3fa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-L) |
| **Counterpart** | `reviews/A_aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ context callers/callees). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function is a constructor | Body assumes list already exists; returns 1/0 not this | **Falsified** — populate worker |
| 2 | cdecl / no this | `MOV EBX,ECX`; field stores via EBX; `ret 0x14` | **Falsified** — **thiscall** |
| 3 | Stack args map linearly to +0x20.. | Bytes: +0x24 gets arg2, +0x28 gets arg1 | **Clarify** — **middle swap** sealed |
| 4 | param_6 is a float scale | Used as ECX for `FUN_004f1e20`; null-tested as pointer | **Falsified** — **context object\***; scale is arg3 |
| 5 | Always succeeds | Early null + lock-fail paths return 0 | **Falsified** — dual status |
| 6 | List is at +0x14 only | `ADD EBX,0x10` before size/insert; head at +0x14 | **Clarify** — list **base +0x10** |
| 7 | DAT_00a0f298 is 1.0 or 2.0 | `read_memory` → `00 00 00 3f` = 0.5f | **Falsified** — **0.5f** |
| 8 | Same unit as convenience ctor | Convenience is `0x005b4260` calling this | **Falsified** — separate VA |
| 9 | Product plate from gfxBody.cpp string | Plate is in **callee** log path, not this unit's identity | **Overclaim risk** — keep structural `_Inferred` |
| 10 | Decompiler ROUND/loop invalidates seal | Bytes show nested accum + node buy/link | **No** — CF sealed; extent field offsets unowned |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 0x14 + status 1/0 | **High** | Ports use wrong cleanup / ignore fail |
| Float store swap | **High** | Dim axes transposed |
| Null ctx gate | **High** | Crash on null vs silent 0 |
| List insert at +0x10 | **High** | Corrupt wrong offset |
| 0.5f half-step | **High** | Grid phase error |
| Node payload English | **Low** | Doc only |
| Product class | **None claimed** | Wrong domain docs |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  if param_6: store F4; lock path; if ok: nested grid insert; return 1
  else/fail: return 0

bytes:
  TEST ESI,[ebp+18]; JZ ret0
  movss stores swapped; CALL 004f1e20 with ECX=ESI
  CALL 00764830; TEST EAX; JL fail
  mul DAT_00a0f298 (0.5f); nested loops; CALL 005b4470 / 005b43d0
  MOV AL,1 / XOR AL,AL; RET 14
```

Clean must **not** invent:

- Returning `this` (ctor myth)
- Linear arg→float mapping without swap
- Treating ctx as scale float
- Product class name from callee plate alone
- Claiming bit-exact loop without locked-rect offsets

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x005b3fa0
uint PopulateListScaledGrid(Obj30 self, float a, float b, float c, float scale, object ctx)
{
    if (ctx == null) return 0;
    self.F20 = a; self.F24 = c; self.F28 = b; self.F2C = 0f;
    EnsureLoaded(ctx, 1, 1);
    // lock path via gfxBody helpers; on fail return 0
    // nested ROUND(a*scale) x ROUND(b*scale) inserts into list at +0x10
    return 1;
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks strengthen ABI/store/status seals; residual product/payload gaps do not block accept-with-gaps.
