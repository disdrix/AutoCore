# Review B (skeptical / adversarial): `aa_00978d20` ClientSpecialEvent_TeleportIn_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00978d20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00978d20_ClientSpecialEvent_TeleportIn_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same object layout as TeleportOut | Alloc **0x50** vs **0x34**; ship slot; pose at `+0x10`; entity at `+0x38` not `+0x24` | **Falsified as same layout** |
| 2 | Identical local-player test as TeleportOut | In: `event+0x38 == DAT_00d1b6d8`; Out: `vt+0x210(0) == DAT_00d1b6d8` | **Distinct** |
| 3 | Always spawns usable ship | Hardpoint fail destroys ship and nulls `+0x28` | **Falsified as always-success** |
| 4 | `"No 35"` is map/sector 35 | Same family as Respawn Update: hardpoint probe **0x23** semantics | **Falsified as map id** (structure) |
| 5 | Ghidra `__thiscall(this=param_1)` is trustworthy | Body constructs `param_2`; asm `mov esi,ecx` + stack object | **ABI mislabel risk** |
| 6 | Caller passes only event pointer | Entity must enter in **ECX** (`iVar5`); one-arg decompile is incomplete | **Entity required** |
| 7 | This is TeleportOut leave sequence | Vtable `PTR_FUN_00a76800` vs Out `…860`; ends `FUN_00978990` not `FUN_009780c0` | **Falsified** |
| 8 | Packet type 2 is Respawn | Respawn is type **0** size **0x70** | **Falsified** |
| 9 | Angle scale is full-turn | Shared `DAT_00aaaa84` → uint16 maps ≈ **π/2** | **Quarter-turn scale** |
| 10 | Live ≠ raw | Live matches raw strings, CBID, geo, hardpoint log | **Match** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type-2 arrive presentation ctor | **High** | Wrong class / size |
| Layout offsets +0x24/+0x28/+0x38/+0x48 | **High** | Crash on tick |
| Hardpoint fail string + destroy ship | **High** | Leak / null ship deref |
| ABI entity-in-ECX | **High** asm / **Medium** if call site reworked | Wrong entity stored |
| Attach glue (`FUN_0044af00` family) | **Medium–Low** | Ship never parents |
| `FUN_00978990` start semantics | **Medium** | Arrive never runs |
| Runtime | **Open** | Visual desync |

---

## 3. Cross-check raw / clean / siblings

| Check | Result |
|---|---|
| Live ≡ `raw/aa_00978d20_*.md` | **Match** |
| Clean + Named TeleportIn cpp present | **Yes** |
| Shares CBID `0xadc` + three anims with TeleportOut | **Yes** |
| Shares `cptest.geo` / hardpoint-35 string family with Respawn Update | **Yes** (arrive/respawn presentation family) |
| Vtable / start helper distinct from Out | **Yes** (`00a76800` / `FUN_00978990`) |
| Sole caller type 2 | **Yes** |

---

## 4. Surviving contract for AutoCore

```
// Client presentation — SpecialEvent type==2 (TeleportIn / arrive).
// ABI: ECX = entity*, stack = Event* (0x50). Returns event*.

Event* ClientSpecialEvent_TeleportIn_ctor(Entity* ent, Event* e)
{
  InstallVtable_TeleportIn(e);           // PTR_FUN_00a76800
  e->entity = ent;                       // +0x38
  e->presentation = e->ship = null;

  auto* obj = AllocateByCbid(0xadc);
  if (!obj) { DebugStop(); return e; }

  BindPresentation(obj);
  e->presentation = QueryGraphics(obj);  // +0x24
  CopyEntityPose_vt1a0(ent, e->pose);    // +0x10..
  ApplyAirliftAnims(e);                  // same three .anm
  e->armed = 1;                          // +0x48

  e->ship = NewShip_0x14c_Load("cptest.geo"); // +0x28
  if (!HardpointProbesOK()) {
    Log("No 35 from INC provided");
    Destroy(e->ship); e->ship = null;
  } else {
    AttachShipToPresentation(e);         // glue callees
  }

  if (ent == g_LocalPlayerToken) {       // DAT_00d1b6d8 direct
    SaveCamMode(e); cam->mode = 4; FUN_0090dd50(); WriteCamPose(...);
  }

  FUN_00978990(e);
  return e;
}
```

**Do not:**

- Reuse TeleportOut layout offsets.
- Drop entity because the clean caller shows one argument.
- Treat hardpoint failure as fatal process exit without nulling ship.
- Unify local-player test with TeleportOut’s `vt+0x210` path without evidence.
- Port Ghidra `operator_delete` noreturn literally.

---

## 5. Open questions

1. Why In uses `vt+0x1a0` pose fetch vs Out `+0x19c` (different interface vs decompiler off-by-one).
2. Why local compare is direct pointer equality here vs vtable query on Out.
3. Product names for hardpoint attach glue (shared with Respawn Update dual residuals).
4. Runtime of hardpoint-fail path (does event still tick without ship?).

**Verdict:** **accept-with-gaps** — arrive vs leave distinctions and hardpoint fail path survive attack; residual risk is ABI documentation at call site and attach glue naming.
