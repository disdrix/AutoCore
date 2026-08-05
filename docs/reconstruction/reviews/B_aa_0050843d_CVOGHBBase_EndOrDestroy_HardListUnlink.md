# Review B (skeptical / adversarial): `aa_0050843d` CVOGHBBase_EndOrDestroy_HardListUnlink

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050843d` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Agent** | W20-R |
| **Counterpart** | `reviews/A_aa_0050843d_CVOGHBBase_EndOrDestroy_HardListUnlink.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Standalone void API callable with empty regs | Trust Ghidra `void FUN_0050843d(void)` | **Falsified as free API** — SEH continuation; needs parent ESI/EBP/EBX |
| 2 | `FUN_005085b0(this)` only | Decompiler single-arg | **Falsified** — bytes set **ECX=listMgr**, push **HB*** |
| 3 | Soft path body is *inside* this function range | Decomp includes stores | **Falsified for body range** — stores at `FUN_0050846f` (`0x0050846f+`); fragment ends `0x00508463` |
| 4 | Hard path skips soft-mark | Assume remove replaces soft | **Falsified** — hard path **jmp** soft tail after remove |
| 5 | This *is* OnEnd | Slot confusion | **Falsified** — OnEnd is parent `vtbl+0x14` before this tail |
| 6 | flag_hard compared as full dword | | **Partial** — byte `cmp [ebp+0xc], bl`; callers push imm 0/1 |
| 7 | Many direct callers | MissionPatrol seed name | **Falsified** — sole caller `FUN_005083f0` (vtbl installs hit parent) |
| 8 | Remove return value gates soft mark | | **Falsified** — return discarded |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hard vs soft gate on `[ebp+0xc]` | **High** | Wrong teardown path |
| listMgr thiscall + HB key | **High** | Crash / no-op remove |
| Always soft-tail | **High** | Leaked dead flag / link |
| Fragment vs free function | **High** | Port as wrong API |
| English fragment name | **Medium** | Doc only |
| Soft-tail dual completeness | **Med** | residual in `aa_0050846f` |

---

## 3. Cross-check against raw

```text
// decompiler (misleading arity):
if (flag_hard && this+0x18 && *(owner+0xb0)) {
  FUN_005085b0(unaff_ESI);   // WRONG modeling
  FUN_0050846f();
  return;
}
// soft stores...

// bytes (authoritative):
if (flag_hard && owner && listMgr) {
  FUN_005085b0(listMgr, this);  // ecx=listMgr, stack=this
}
→ FUN_0050846f soft mark
```

Clean **must** pass listMgr as this for `FUN_005085b0`. Scaffold that called `FUN_005085b0(unaff_ESI)` alone is **rejected**.

---

## 4. Surviving contract for AutoCore

```
// Inside CVOGHBBase_EndOrDestroy after optional OnEnd:
set SEH state = 3
if flag_hard and this.ownerLink(+0x18) and owner.listMgr(+0xb0):
    ListMgr_RemoveByKey(listMgr, this)   // FUN_005085b0
// always:
this.deadFlag(+0x20) = 1
this.ownerLink(+0x18) = 0
restore SEH; ret 8
```

**Port tests:**

* `(flag_onEnd=0, flag_hard=0)` never calls OnEnd or list remove; soft-marks.
* `(1, 1)` with live list: OnEnd then remove then soft-mark.
* Never call `FUN_005085b0` with HB as ECX from this site.

---

## 5. Open questions

1. Dual seal of `FUN_0050846f` if treated as separate unit.
2. Owner vs list-manager type names at `+0x18` / `+0xb0`.
3. Interaction with scalar deleting dtor when remove's node dtor runs.

**Verdict:** **accept-with-gaps**
