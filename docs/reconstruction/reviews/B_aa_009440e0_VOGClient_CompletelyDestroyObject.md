# Review B (skeptical / adversarial): `aa_009440e0` VOGClient_CompletelyDestroyObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_009440e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009440e0_VOGClient_CompletelyDestroyObject.md` |
| **System** | `inventory-transfer` / client object lifecycle |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on identity + refuse + main stages; **reject** “simple free” or “always 3-arg” claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Can delete local player character | **Falsified** — early compare vs `client+0xE98` object + hard assert string |
| 2 | Server authoritative destroy only | **Falsified** — client VOGClient path; used from S2C handlers but body is client |
| 3 | Only frees memory | **Falsified** — unbind parents, inventory unstamp, UI, gfx, selection, logs |
| 4 | Decompiler 3-arg signature is complete | **Falsified** — call sites push force/death + `0xFFFFFFFF` sentinels; EDI=this |
| 5 | Same as inventory unequip | **Falsified** — unequip may **call** this for orphaned objects; not the equip apply path |
| 6 | No class branching | **Falsified** — `clonebase+0x38` multi-arm switch |
| 7 | Bit-exact ready | **Fail** — large residual branches + arity |

---

## 2. Decisive dataflow (SEALED)

```
this = EDI  (VOGClient)
obj  = stack

player = ObjectFrom(this[+0xE98])
if obj == player:
  assert "Attempting to delete your character... bad bad"; return

log CompletelyDestroyObject(COID, global, CBID, unique, force, death)
// selection clear, validate, unlink, clear FX
switch (obj.clonebase[+0x38]):
  0x0E / 0x14 / 0x12 / 0x16 / default → type-specific unbind
// optional net + gfx host FUN_004962b0 + finalize
```

Entry bytes: `sub esp,8`; load `[edi+0xE98]`; compare to resolved player object vs stack object.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CompletelyDestroyObject identity | **High** | Wrong lifecycle API |
| Character refuse | **High** | Client self-delete bug |
| EDI = VOGClient | **High** | Wrong this |
| Class arms all fully understood | **Med** | Missed side effect in rare class |
| force/death semantics | **Med** | Wrong death FX / force flags |
| Runtime | **Open** | Residual |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `param_1` is client | Compatible? | **No** — client is EDI; param is object |
| COID at `+0x58` dwords only | Compatible? | **Yes** for log — matches object id layout |
| Skip validate always destroys | Hidden? | **No** — still proceeds after warn (log-only on null validate) |
| Inventory-only | Compatible? | **No** — general object destroy |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `Client_RecvInventoryEquip` | Destroy item when vehicle missing; destroy previous-out after hardpoint equip |
| `Client_RecvInventoryUnequipNotify` | Destroy detached component objects |
| Drop / DestroyObject S2C paths | Additional callers |
| `aa_0092f120` | Shared gfx-host refresh pattern (`+0xE04/+0xE898`) |
| `CVOGObject_SetInteractSpecialFX` | Clears FX before unlink |
| `FUN_00571b60` | Inventory “is held/tracked” gate on default arm |

---

## 6. Verdict

**accept-with-gaps.** Name and core safety/log/unlink architecture are **sealed** by retail strings and entry bytes. Treat decompiler arity and deep class arms as **partial** until a full human refine. Do **not** use as a trivial `delete obj`.
