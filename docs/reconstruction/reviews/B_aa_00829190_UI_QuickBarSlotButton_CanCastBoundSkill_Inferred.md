# Review B (skeptical / adversarial): `aa_00829190` UI_QuickBarSlotButton_CanCastBoundSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829190` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` |
| **System** | client UI / quickbar / skills-abilities |
| **Dual status** | **Present** (WQ8R-D) |
| **Verdict** | **accept-with-gaps** on CF/ABI/gates; **reject** overclaims of product flag names, that this is the 0x2030 cast sender, or that skipBusy is always 0 |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This function sends C2S cast / 0x2030 | **Falsified** — pure predicate; no net send; callees are validate/resolve/equals only |
| 2 | Same as `Client_QuickBarActivateSkillSlot` | **Falsified** — different VA; Activate builds packet; this only returns bool |
| 3 | payloadKind check is item (2) | **Falsified** — `CMP …,1` skill only |
| 4 | LocalCastValidate skipBusy always 0 | **Falsified** — this site **`push 1`** |
| 5 | Accepts only code 0 | **Falsified** — also accepts **6** (busy) |
| 6 | Always resolves target | **Falsified** — skipped when `+0x614&0x800` set or force-true |
| 7 | Compares to `g_abTfidInvalid_A15870` pointer | **Fail as identity** — uses **`DAT_00a1e810`** (content-same, different VA) |
| 8 | Decompiler `(char)skill` is real truncation | **Falsified** — `push esi` full pointer |
| 9 | Multi-arg stdcall | **Falsified** — ECX this only; `RET` |
| 10 | PDB-confirmed name without `_Inferred` | **Fail** — role inferred |
| 11 | Bit-exact complete | **Fail** — runtime open |

---

## 2. Decisive dataflow

```
button = ECX
if !DAT_00d1b6d8 or button.payloadKind!=1 or button.skill==null: return false
if DAT_00d1b644 && DAT_00d1b644.byte_f5: return true

seed TFID/aim from local character (selection +0xa4 or self; vtbl+0x1a0)
code = LocalCastValidate(localChar, skipBusy=1, skill, 0)
if code not in {0, 6}: return false

if (skill.flags_614 & 0x800) != 0: return true
resolved = ResolveCastTarget(...)
return !TFID_EqualsObjectId(resolved, DAT_00a1e810)
```

### Byte attacks that landed

| Attack | Result |
|--------|--------|
| skipBusy=0 at all sites | **This site uses 1** |
| Only code 0 ready | **6 allowed** (UI busy-tolerant) |
| Invalid sentinel must be A15870 | **A1E810 used**; same 16 B content |
| jle polarity vs decompiler | **Matches** decompiler when jle target = resolve (skip true-ret block) |

---

## 3. Confidence table (adversarial)

| Dimension | Level |
|---|---|
| Boundary / ABI / bool | **Confirmed** |
| Skill kind + skill* gates | **Confirmed** |
| Validate accept {0,6} + skipBusy=1 | **Confirmed** |
| Resolve/invalid when bit clear | **Confirmed** |
| Call site is icon enable | **High** (nearby `+0x4fe`); owning FUN label open |
| Product flag names | Open / Tentative |
| Runtime | Open |

---

## 4. Residual attacks (open)

1. Exact semantic of `0x800` (self-cast? no-target? AoE free?).  
2. Who sets `DAT_00d1b644+0xf5`.  
3. Whether force-true is debug/tutorial only.  
4. Full disassembly of caller's icon-on/off branch (not owned; no disassemble_bytes).

---

## 5. Verdict

**accept-with-gaps** — body formula sealed; reject activation/send conflation and non-`_Inferred` naming. Runtime remains open.
