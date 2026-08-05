# Annotated low-level: Client_CastSkillFromQuickBarSlot (`aa_009418e0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_009418e0` |
| **VA** | `0x009418e0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_009418e0_Client_CastSkillFromQuickBarSlot.md` (capture 2026-07-23) |
| **Related** | Thin pre-resolver that ends in `Client_RequestCastSkill` |

---

## 1. Corrected signature

```c
// Client context in ESI (Confirmed 2026-07-29 dual residual — not EAX)
// skillId @ [EBP+8]; stdcall RET 4
void Client_CastSkillFromQuickBarSlot(int skillId);
```

| Name | Width | Origin | Role |
|---|---|---|---|
| `client` | ptr | **ESI** (caller-set; `MOV EAX,ESI` before block probe) | Client root (`+0xe98` character) |
| `skillId` | i32 | stack `[EBP+8]` | Skill id to look up and cast |

Dual residual: `reviews/a_009418e0.md`. `FUN_0093bac0` = `Client_PromptSkillTargetSelect` (EAX=skillId → `client+0x30c0`). `FUN_0093b7f0` = cast-block + “You can't do that while you are …” feedback.

---

## 2. Control flow

```text
// Defaults: TFID = g_abTfidInvalid_A15870; aim float4 = 0
if FUN_0093b7f0() != 0: return                    // cast blocked / UI modal? Probable

pSkill = character(client+0xe98)->vtbl+0x234(skillId)
if pSkill == 0: return

flags = *(u32*)(pSkill + 0x614)

if (flags & 0x800) == 0:
    // Need explicit target / aim resolution
    if character has NO +0xa4 linked object:
        // use self or current target via vtbl+0x19c seat chain
        // copy object TFID from entity+0x160..0x16c
        // aim = character->vtbl+0x1a0()  // position getter Probable
    else:
        // use linked object (+0xa4) TFID @ +0x160
        // if linked skill-flags bit (obj[0x5f]>>5)&1 == 0: skip aim fill (goto send)
        // else vtbl+0x1c8 + FUN_00404c90 → aim/pos
    copy aim dwords into stack float buffer

else if (flags & 0x20) == 0:
    FUN_0093bac0(client, 1)                       // retarget / enter targeting mode Probable
    return                                         // do NOT send yet

// fallthrough label LAB_00941a89
Client_RequestCastSkill(skillId, tfid_lo, tfid_hi, tfid_b, tfid_p, &aim)
```

---

## 3. Flag interpretation (`pSkill+0x614`)

| Bit mask | Observed behavior | Confidence |
|---|---|---|
| `0x800` | When **clear**: function gathers TFID+aim before cast | **High** (control flow) |
| `0x800` | When **set**: skip gather; may require targeting mode | **High** |
| `0x20` | When `0x800` set and `0x20` clear: call `FUN_0093bac0` and **return** (defer cast) | **High** |
| `0x20` | When set with `0x800`: fall through to RequestCast with invalid/default TFID | **Probable** self/ground skill |

These bits belong to `eSkillFlagBits_inferred` (topic). Retail names **open**.

---

## 4. Side-effect order

1. Gate call `FUN_0093b7f0` (read-only **Probable**).
2. Skill lookup via character vtbl `+0x234`.
3. Conditional reads of target TFID (`+0x160`) and aim helpers.
4. Either **return after** `FUN_0093bac0` (targeting UI) **or**
5. **Tail-call style** `Client_RequestCastSkill` (validate, HB, send `0x2030`).

No direct network I/O in this function.

---

## 5. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `unaff_ESI` | Client object register arg | **High** |
| `local_14` byte[16] vs TFID dwords | Stack TFID_16 storage; invalid sentinel init | **High** |
| `uStack_34` aim buffer | 3–4 dwords position; passed as `pAimPos` | **High** |
| `piVar1[0x5f]` bit test | `*(u32*)(linked + 0x17C)` bit 5 — object capability flag | **Probable** |

---

## 6. Relationship to other cast entry points

| Entry | Role |
|---|---|
| `Client_QuickBarActivateSkillSlot` | Slot index → skill; builds `0x2030` itself |
| `Client_CastSkillFromQuickBarSlot` | skillId → resolve target/aim → **RequestCastSkill** |
| `Client_RequestCastSkill` | validate + optimistic HB + send |

---

## 7. Open questions

- Retail name/behavior of `FUN_0093b7f0` and `FUN_0093bac0`.
- Full `+0x614` bit dictionary.
- Whether all hotbar keys use this path vs ActivateSkillSlot only.
