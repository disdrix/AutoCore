# Review A (reconstruction fidelity): `aa_006082e0` Outpost_CaptureOutpost

| Field | Value |
|---|---|
| **Stable ID** | `aa_006082e0` |
| **VA** | `0x006082e0` |
| **Body** | `0x006082e0`–`0x00608614` |
| **Canonical name** | `Outpost_CaptureOutpost` |
| **Former name** | `FUN_006082e0` |
| **Review date** | `2026-07-29` (W20-D) |
| **Reviewer role** | Reconstruction fidelity (outpost capture) |
| **Counterpart** | `reviews/B_aa_006082e0_Outpost_CaptureOutpost.md` |
| **System** | skills-abilities / outpost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Transfer outpost ownership to the capturer's root race when gates pass: credit nearby same-race entities, run old→new faction bank helpers, cast faction skills, store `this+0x234`, recompute beacon-share ratio, and arm timer/schedule.

This is the **owner** of the CaptureOutpost product path previously cited only as caller context by `Outpost_CastSkillsForFaction` / `Outpost_UpdateBeaconShareRatio` duals.

---

## 2. Inspected evidence

| Source | Detail |
|---|---|
| Live Ghidra | `decompile_function` `0x006082e0`; callees list; xrefs |
| `read_memory` | body @ `0x006082e0` (256+256+64 through `ret 4`); string @ `0x009dec4c` |
| Call-site ABI | `get_assembly_context` @ `0x0057c88d`, `0x00650752` |
| Raw | `docs/reconstruction/raw/aa_006082e0_FUN_006082e0.md` (+ 2026-07-29 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_006082e0_FUN_006082e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_CaptureOutpost.cpp` |
| Sibling duals | CastSkillsForFaction, UpdateBeaconShareRatio, GetRootRaceId |
| String | `"Invalid faction in CaptureOutpost = %d"` |

**Tools:** decompile + read_memory (+ callers/callees/assembly_context). **No** `disassemble_bytes`. **No** Launcher.

---

## 3. Signature

```c
// MSVC __thiscall: ECX = outpost; stack capturerCtx; RET 4
void __thiscall Outpost_CaptureOutpost(void *thisOutpost, void *capturerCtx);
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX = this | `8B F1` / prologue | **High** |
| One stack arg | epilogue `C2 04 00`; `mov ecx,[ebp+8]` | **High** |
| capturerCtx nullable | null check before vtbl call | **High** |

---

## 4. Control flow (sealed)

```
newFaction = 3
if capturerCtx:
  capturer = capturerCtx->vtbl[+0x210](0)
  if capturer: newFaction = Object_GetRootRaceId(capturerBase)

if 0 <= oldFaction(+0x234) < 3: FUN_004cd5f0(old)
if capturer && raceByte < 3: FUN_004cd5d0(raceByte)

if newFaction == old OR timerBlob(+0x248) == 0: return

if newFaction < 0 OR newFaction > 3:
  log("Invalid faction in CaptureOutpost = %d", newFaction); return

FUN_005743e0(0,0,0)
if capturer: creditNearbySameRace(radiusSq from +0x218)

if world[+0x7e] == 0: return

FUN_00606820(old); FUN_00606890(old); FUN_00606ff0(old)
FUN_00606900(new); FUN_00606a00(new)
Outpost_CastSkillsForFaction(new)
FUN_00606a70(new, capturerBaseOr0)
*(+0x234) = new
Outpost_UpdateBeaconShareRatio()
*(+0x238) = scheduleCount; *(+0x23c) = 0
timer[+8] = FUN_00607550(); timer[+0x14] = GetTickCount()
FUN_006081b0(capturer)
return
```

### Offsets

| Off | Role |
|---:|---|
| `+0x218` | radius float |
| `+0x220` | schedule bank select |
| `+0x234` | faction |
| `+0x238` / `+0x23c` | schedule count / cursor |
| `+0x248` | timer blob |

### Constants / DATs

| Symbol | Role |
|---|---|
| seed `3` | default race before capturer resolve |
| `0x009dec4c` | invalid-faction format string |
| `DAT_00d029f4/f8` | default schedule vector |
| `DAT_00d029e4/e8` | alt schedule when `+0x220 != 0` |

---

## 5. Call graph

| Address | Name | Role |
|---|---|---|
| `0x00512440` | `Object_GetRootRaceId` | capturer + neighbors |
| `0x00606d70` | `Outpost_CastSkillsForFaction` | success path cast |
| `0x006078e0` | `Outpost_UpdateBeaconShareRatio` | after faction store |
| `0x007a4480` | log | invalid faction |
| EXTERNAL | `GetTickCount` | timer stamp |
| `0x004cd5f0` / `0x004cd5d0` | FUN_* | pre-capture side effects |
| `0x00606820`…`0x00606a70` | FUN_* | old/new bank helpers |
| `0x00607550` / `0x006081b0` | FUN_* | timer value / post notify |
| Callers | `0x0057c88d`, `0x00650752` | live capture entry |

---

## 6. Side effects

- May write `this+0x234`, `+0x238`, `+0x23c`, timer blob fields.
- Invokes skill cast + beacon-share ratio recompute.
- Credits nearby same-race objects (helper `FUN_00418d70`).
- Logs on invalid faction.
- **No** direct network in this unit (helpers may).

---

## 7. Confidence

| Area | Level |
|---|---|
| CF + ABI + body range | **High** |
| Product string / name | **High** (string) / **Inferred** (method English) |
| Success chain order | **High** |
| Dualed callees identity | **High** |
| Unresolved helper meaning | **Medium / Tentative** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product C++ class/method English beyond CaptureOutpost string.
2. Dual seals for pre/post bank helpers (`00606820`…`00606a70`, `006081b0`, `004cd5*`).
3. capturerCtx type + vtbl `+0x210` contract.
4. `FUN_00418d70` credit semantics.
5. Schedule bank DAT contents / `+0x220` product meaning.
6. Runtime / differential verification.

**Verdict:** **accept-with-gaps**
