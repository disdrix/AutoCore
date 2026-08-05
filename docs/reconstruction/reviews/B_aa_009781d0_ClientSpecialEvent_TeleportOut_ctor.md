# Review B (skeptical / adversarial): `aa_009781d0` ClientSpecialEvent_TeleportOut_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_009781d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009781d0_ClientSpecialEvent_TeleportOut_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the S2C packet parser for teleports | No bitstream; only ctor + presentation setup; packet parse is `Client_RecvSpecialEvent` | **Falsified** |
| 2 | Handles all special-event types | Caller gates type **1** only; sizes differ (0x34 vs 0x50 vs 0x70) | **Falsified** |
| 3 | Always mutates camera | Camera block only if `entity vt+0x210(0) == DAT_00d1b6d8` | **Falsified as always** |
| 4 | CBID fail aborts without returning object | Still `return this` after `FUN_007a4480` | **Half-init return possible** |
| 5 | `CVOGReaction_GiveItemByCbid` grants inventory item | Used as presentation/object factory by CBID; name is overloaded | **Name overstates inventory** |
| 6 | `DAT_00aaaa84` is 2π/65536 full-turn scale | `read_memory` ≈2.39688e-5; ×65536 ≈ **π/2**, not 2π | **Falsified as full-turn** — quarter-turn over uint16 |
| 7 | Update / tick logic lives here | Ends in `FUN_009780c0`; no phase machine in body | **Falsified** |
| 8 | Multiple callers | Sole xref `Client_RecvSpecialEvent` `0x0080cd8a` | **Single caller** |
| 9 | Bit-exact / runtime proven | Static decompile + memory only | **Open** if claimed finished |
| 10 | Raw scaffold body is stale vs live | Live `batch_decompile` matches raw CF, strings, CBID, camera block | **Match** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type-1 leave presentation ctor | **High** | Wrong event class |
| Size `0x34` / entity `+0x24` / gfx `+0x10` | **High** | Heap overwrite / null deref |
| Three airlift anim strings | **High** | Missing assets / silent no-op |
| Local-only camera path | **High** | Remote entities steal camera |
| Angle scale numeric | **High** | Wrong random yaw range |
| Product meaning of CBID `0xadc` | **Medium** | Wrong asset binding |
| `FUN_009780c0` start contract | **Medium** | Event never ticks |
| Runtime parity | **Open** | Visual desync |

---

## 3. Cross-check raw / clean / caller

| Check | Result |
|---|---|
| Live decompile ≡ `raw/aa_009781d0_*.md` | **Match** (CBID, anims, camera, `FUN_009780c0`) |
| Clean `FUN_009781d0.cpp` scaffold present | **Yes** (generic names) |
| Caller type 1 → `operator_new(0x34)` + `(event, entity)` | **Consistent** |
| Pair TeleportIn type 2 / size `0x50` | **Distinct** class |
| `DAT_00aaaa84` only 3 xrefs (shared with TeleportIn) | Tight constant — not a global 1.0 pool |

---

## 4. Surviving contract for AutoCore

```
// Client presentation only — server already decided teleport/leave.
// Constructed from SpecialEvent S2C type==1.

Event* ClientSpecialEvent_TeleportOut_ctor(Event* e /*0x34*/, Entity* ent)
{
  InstallVtable_TeleportOut(e);          // PTR_FUN_00a76860
  ZeroFlags(e);                          // +0x04,+0x08,+0x30,+0x31
  e->entity = ent;                       // +0x24
  e->presentation = null;                // +0x10

  auto* obj = AllocateByCbid(0xadc);
  if (!obj) { DebugStop(); return e; }

  BindPresentation(obj);
  e->presentation = QueryGraphics(obj);  // vt+0x1cc

  auto q = RandomUnitOrientation();      // sin/cos * DAT_00aaaa84
  auto pose = ExtractEntityPose(ent);    // vt+0x19c path
  ApplyPoseAndAnims(e, pose, q);         // airlift_at / _aut / _at2
  FUN_005816a0(1, 0);

  if (IsLocalPlayerToken(ent)) {
    e->camCookie = cam->mode;            // +0x0c / +0x60c
    cam->mode = 4;
    FUN_0090dd50();
    WriteCamTargetPose(cam, pose, q);    // +0xce4..
  }

  FUN_009780c0(e);                       // start leave sequence
  return e;
}
```

**Do not:**

- Implement packet parsing here.
- Assume camera always changes.
- Treat CBID helper as inventory give semantics without its own dual.
- Use full-turn 2π/65536 for `DAT_00aaaa84`.
- Claim Update/phase logic is in this VA.

---

## 5. Open questions

1. Product asset for CBID `0xadc` (INC ship / airlift prop?).
2. Exact role of `FUN_009780c0` vs sibling Update VA (out of own-only scope).
3. Whether CBID-fail objects are freed by caller or leaked half-init.
4. Runtime capture of local vs remote camera branches.

**Verdict:** **accept-with-gaps** — adversarial pass leaves leave-ctor layout, anims, and local camera gate intact; residual risk is helper naming and CBID asset identity.
