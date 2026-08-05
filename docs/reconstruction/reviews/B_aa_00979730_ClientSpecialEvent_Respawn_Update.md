# Review B (skeptical / adversarial): `aa_00979730` ClientSpecialEvent_Respawn_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979730` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00979730_ClientSpecialEvent_Respawn_Update.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the S2C SpecialEvent packet handler | No bitstream/read; only vtable DATA xref; recv is `Client_RecvSpecialEvent` → ctor | **Falsified** — presentation tick only |
| 2 | Always runs full 0..7 sequence | Phase 2 early `return 1` when `this+0x38 == 0`; cancel `+0x08` skips machine | **Falsified as always-full** |
| 3 | Return 0 means failure | Most active ticks return 0 while still animating; 1 = complete | **Falsified as failure code** |
| 4 | Phase 0 waits on `phaseTime + Δ` like others | Gate is **absolute** `elapsed >= DAT_00aaa8b0` | **Distinct** — absolute gate |
| 5 | `g_flLevelUpUiBase_Inferred` is respawn-specific UI | Shared float `2.0f` @ `0x00a10e74` (254 xrefs; level-up UI plate) | **Overstated name** — value **High**, semantic name **Low** |
| 6 | `"No 35 from INC"` means sector 35 / map id | `FUN_0040d4b0(0x23)` with 0x23==35; paired with `FUN_0040d4b0(0)` hardpoint probes | **Falsified as map id** — hardpoint/index **35** |
| 7 | Teleport every frame always | Lift-follow only when `+0x6c`; dest snap only phase 2 transition | **Falsified** |
| 8 | Camera always manipulated | Local-only: `vt+0x210(0) == DAT_00d1b6d8` | **Falsified as always** |
| 9 | Direct callers exist in code | Sole xref is vtable DATA `0x00a76720` | **Falsified as static call** — virtual Update |
| 10 | Bit-exact / runtime proven | Static decompile + `read_memory` only | **Overstated if claimed finished** |
| 11 | Nested decomp is unreadable / unportable | Nested high→low is standard single-transition-per-tick expansion of `if phase==N && elapsed>=…` | **Portable** if temps recomputed per phase |
| 12 | Phase 7 is entered then work continues | Phase 6→7 sets 7 and **returns 1** immediately | **No further work in this function** after 7 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Virtual Update role / INC airlift presentation | **High** | Wrong system ownership |
| ABI ECX=this, stack float dt | **High** | Wrong tick signature |
| Phase byte `+0x6d`, elapsed `+0x60`, phaseTime `+0x64` | **High** | Broken animation timing |
| Timing floats via `read_memory` | **High** | Wrong hold times |
| Return 1 = finished | **High** | Event list never frees / frees early |
| `+0x38` short-circuit complete | **High** | Infinite hang or skip teleport wrongly |
| `cptest.geo` + hardpoint 35 string | **High** | Wrong asset / silent fail |
| Local camera restore path | **High** structure / **Medium** field names | Stuck camera on local respawn |
| `FUN_005816a0` mode meanings 0–3 | **Medium** | Wrong blend/camera stage |
| Ship attach / hardpoint glue callees | **Medium–Low** | Airlift never attaches |
| Exact float 3.433 / 0.566 product intent (designed vs bake) | **Medium** | Slight timing drift if rounded |
| Runtime parity | **Open** | Visual desync vs retail |

---

## 3. Cross-check against raw / clean / ctor

| Check | Result |
|---|---|
| Live decompile ≡ `raw/aa_00979730_*.md` body | **Match** (phase nest, strings, returns) |
| Clean `ClientSpecialEvent_Respawn_Update.cpp` CF ≡ raw | **Match** (scaffold; extra blank lines only) |
| Ctor `0x00979650` zeros `+0x60/+0x64/+0x6c/+0x6d`, sets TFID/`+0x38`/dest, installs vtable | **Consistent** with Update field use |
| Ctor calls `FUN_00979310` once; Update calls it on `+0x08` | **Consistent** cancel/init helper |
| Vtable DATA-only xref | **Match** virtual method model |
| `DAT_00aaa8b0` only 3 xrefs (tight constant) | Supports respawn-local timing, not global 1.0 pool |
| `g_flOne` / `g_flLevelUpUiBase` shared pools | Values sealed; names not respawn-owned |

---

## 4. Surviving contract for AutoCore

```
// Client presentation only — server already decided respawn / dest pose.
// Virtual Update on special-event object (not a packet handler).

bool ClientSpecialEvent_Respawn_Update(Event* e, float dt)
{
  if (e->cancelFlag) { // +0x08
    RespawnEvent_Helper_00979310(e);
    return false; // keep? product: return 0
  }

  e->elapsed += dt; // +0x60

  TickGraphics(e->gfxRoot);           // +0x10
  Entity* ent = ResolveTfid(e->tfid); // +0x28

  if (e->liftFollow) { // +0x6c
    // TeleportTarget(ent, shipPos - e->liftOrigin)
  }

  // Single phase transition per tick (priority high phase first in decomp):
  // 6→7 complete (Δ4) return true
  // 5→6 (Δ2)  FUN_005816a0(2,0.1)
  // 4→5 (Δ1)  clear liftFollow; FUN_00979290; local camera restore
  // 3→4 (Δ≈3.433) FUN_005816a0(0,0.1)
  // 2→3 (Δ4)  if !e->fullSequenceFlag(+0x38) return true;
  //            orient; local camera attach; TeleportTarget(dest+0x40); apply quat +0x50
  // 1→2 (Δ≈0.566) FUN_005816a0(2,0.1)
  // 0→1 if elapsed>=≈3.433: spawn cptest.geo, require hp 35+0, liftFollow=1, FUN_005816a0(3,0.1)

  return false;
}
```

**Do not:**

- Implement this as network receive or sector simulation authority.
- Treat return 0 as error.
- Use level-up UI semantics for the 2.0f constant.
- Skip the `+0x38` early-complete path.
- Port decompiler `fVar8`/`fVar9` reuse literally across phases.
- Claim hardpoint / camera helper names are product-final without their own duals.
- Claim bit-exact without capture.

---

## 5. Open questions

1. Product English for `FUN_005816a0` modes `0/1/2/3` (camera rail? anim graph? fade?).
2. What `FUN_00979290` / `FUN_00979310` exactly free (ship only vs full gfx root) — sibling VAs, out of own-only scope.
3. Whether `+0x0c` camera cookie is set in ctor path or only elsewhere.
4. Whether phaseTime absolute vs relative on phase 0 matters if ctor ever non-zero `+0x64` (ctor zeros it today).
5. Runtime capture of full vs short (`+0x38==0`) sequences and local vs remote camera branches.

**Verdict:** **accept-with-gaps** — adversarial checks leave the phase machine, layouts, and sealed floats intact; residual risk is helper product naming and attach/camera glue, not the Update contract itself.
