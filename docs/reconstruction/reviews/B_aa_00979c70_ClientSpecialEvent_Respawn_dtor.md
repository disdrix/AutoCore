# Review B (skeptical / adversarial): `ClientSpecialEvent_Respawn_dtor` @ `0x00979c70`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00979c70_ClientSpecialEvent_Respawn_dtor.md` |
| **Verdict** | **accept-with-gaps** on teardown CF; **needs-more-evidence** on global/DAT semantics |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always restores camera | **Falsified** — only if lookup object vfunc+0x210 result == DAT_00d1b6d8 |
| 2 | Always deletes ship | **Falsified** — gated on this[4] non-null |
| 3 | Attachment always unlinked | **Falsified** — needs ship+8 and this[5] |
| 4 | First vtbl store is final | **Falsified** — ends on base PTR_LAB_00a766f8 |
| 5 | this[3] is always a camera id | **Overstated** — used as camera field write only on local path; semantic tentative |
| — | Runtime verified | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Teardown order ship → attach → camera → base | High | Use-after-free / hang |
| Local-only camera restore | High | Wrong camera for other players' events |
| Field slots [3]/[4]/[5]/[+10 TFID] | High | Layout mismatch |
| DAT_* global meanings | Medium | Wrong singleton wiring |
| FUN_* identities | Medium | Incomplete port |

---

## 3. Surviving contract for AutoCore

```
ClientSpecialEvent_Respawn_dtor(this):
  this.vtbl = Respawn_Update_vtbl
  if ship = this[4]:
    if ship.flag@+8 and attach=this[5]: detach(attach)
    cleanup(ship this-adjust)
    ship.vfunc(+0x2a8)(global_ctx)
    ship.dtor_delete()
  if attach=this[5]: attach.dtor_delete()
  obj = lookup(this+10 /*TFID*/)
  if obj and obj.vfunc(+0x210)(0) == g_LocalPlayer:
    g_CameraField(+0x60c) = this[3]
    camera_refresh()
  base_special_event_dtor()
  this.vtbl = ClientSpecialEvent_base_vtbl
```

---

## 4. Open questions

1. Identity of DAT_00d1b6d8 / DAT_00d1b778 / DAT_00d1b644.
2. Whether FUN_00979290 is shared base dtor for all ClientSpecialEvent subclasses.
3. Relationship to Respawn_Update `0x00979730` and RecvSpecialEvent ctor path.

**Verdict:** **accept-with-gaps** — safe behavioral map for airlift teardown; globals remain open.
