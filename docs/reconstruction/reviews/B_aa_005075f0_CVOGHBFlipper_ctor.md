# Review B (skeptical / adversarial): `aa_005075f0` CVOGHBFlipper_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005075f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005075f0_CVOGHBFlipper_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Generic HB factory (no physics) | Ignore flipper string + constraint alloc | **Falsified** — plate string + `0x50` constraint + `FUN_0055fe50` register |
| 2 | Re-entry path still builds constraint | Miss `host+0x102` gate | **Falsified** — early `FUN_005083f0(0,0)` return |
| 3 | `FUN_005083f0` early call is full OnEnd | Assume always vcalls `+0x14` | **Falsified** — dual zero flags → skip OnEnd (see `aa_005083f0` dual) |
| 4 | Axis tables are random float noise | No `read_memory` | **Falsified** — unit axes `(0,1,0,0)` / `(0,0,1,0)` / `(1,0,0,0)` |
| 5 | Mode `+0x4ce==2` unused here | Only VehicleAction | **Falsified** — selects `DAT_00af1900` vs `DAT_00af18f0` |
| 6 | Float imm is 1.0 / gravity / dt | Guess | **Falsified** — imm **`0x3dcccccd` = 0.1f** |
| 7 | Fail path still registers null action | Soft-fail | **Falsified** — only `FUN_007a4480` log; no `FUN_0055fe50` |
| 8 | `this` discarded on fail | Return null | **Falsified** — always returns constructed HB storage |
| 9 | Sole caller is AI driver | Chain-name alias | **Falsified** — ≥3 callers including client/debug paths |
| 10 | Name `CVOGHBFlipper_ctor` is PDB-proven | Symbol inflation | **Not sealed** — **Probable** from string; Ghidra `FUN_005075f0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Re-entry `+0x102` | **High** | Double-constraint / double-register |
| Axis A/B + 0.1f | **High** | Wrong hinge orientation / scale |
| Register only on full null-chain pass | **High** | Crash vs log divergence |
| `FUN_00600140` / `FUN_0055fe50` roles | **High** | Orphan constraint / unregistered action |
| Product class name | **Medium** | Naming only |
| Host vtbl `+0x28` meaning | **Low–Med** | Pre-build side effect unknown |

---

## 3. Cross-check against raw

```text
// raw aa_005075f0 ≡ live 2026-07-29
CVOGHBBase_ctor(this);
*this = PTR_FUN_009cda10;
if (host[+0x102]) { FUN_005083f0(this, 0, 0); return this; }
AttachOwner; host[+0x102]=1; SetPeriod(1,true);
this[+8]=tag; this[+0x28]=host; this[+0x24]=0;
host->vtbl[+0x28]();
// optional axisB from vehicle mode +0x4ce
p = alloc(0x50); tag p+4 = 0x50;
flip = FUN_00600140(p, host+8, &DAT_00af18e0, &axisB, 0.1f);
this[+0x24] = flip;
if (host && map && world && flip) FUN_0055fe50(world, flip);
else log("Crazy null checking on the flipper...");
return this;
```

---

## 4. Surviving contract for AutoCore

```
CVOGHBFlipper_ctor(this, host, tag):
  base_ctor; vtbl = flipper_vtbl
  if host.flag_102: EndOrDestroy(this, callOnEnd=0, hard=0); return this
  attach owner; host.flag_102 = 1; period = (1, true)
  this.tag = tag; this.host = host; this.constraint = null
  host.vcall(+0x28)
  axisB = (mode+0x4ce==2) ? X_axis : Z_axis   // unit vectors in DAT_
  constraint = new FlipperConstraint(host+8, Y_axis, axisB, 0.1f)  // size 0x50
  this.constraint = constraint
  if host && map(+0xa8) && world(map+0xe4a4) && constraint:
      Phys_RegisterAction(world, constraint)
  else:
      log fail with v/m/w/f components
  return this
```

**Port tests:**

* Must not double-build when `host+0x102` set.
* Must pass **0.1f** and correct unit axes (not identity matrix).
* Must not call `FUN_0055fe50` when any of host/map/world/constraint is null.
* Must still return `this` after fail log.

---

## 5. Open questions

1. RTTI / true class of `FUN_00600140` object.
2. Whether fail path should be hardened in ports (retail logs and keeps HB).
3. Relationship of AI-driver callers vs debug `forceflipper`.

**Verdict:** **accept-with-gaps**
