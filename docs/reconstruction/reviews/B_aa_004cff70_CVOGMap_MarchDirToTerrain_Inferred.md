# Review B (skeptical / adversarial): `aa_004cff70` CVOGMap_MarchDirToTerrain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cff70` |
| **VA** | `0x004cff70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004cff70_CVOGMap_MarchDirToTerrain_Inferred.md` |
| **Verdict** | **accept-with-gaps** (CF High; name + hit-lerp residual) |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `CVOGMap_CastTerrainHeight` (`0x004cfe60`) | Vertical HF+collision cast returns float Y | **Falsified** — step march, bool return, only `FUN_005a58c0`, no `FUN_0055e530` |
| 2 | Wheel / `TtPhantom::castRay` path | Physics suspension cast | **Falsified** — map HF sample only |
| 3 | Returns terrain Y in ST0 | Sibling pattern | **Falsified** — EAX **0/1** |
| 4 | `maxSteps` is world meters | Arg name “range” in pick clean comment | **Falsified as meters** — integer loop budget; callers pass **400 steps** |
| 5 | Null HF still writes out | Always init out | **Falsified** — null HF skips body, return 0, out untouched |
| 6 | Buried start immediately returns hit | First sample under terrain | **Falsified** — must **emerge** then re-enter surface loop |
| 7 | Hit always interpolates X/Z meaningfully | Blend formula present | **Weakened** — if out pre-written as current, blend is identity; **Y not snapped** to HF |
| 8 | Product name known | DriveControlTick callee alias | **Open** — `_Inferred`; dual must not invent PDB English |
| 9 | Only DriveControlTick uses it | Partition map label | **Falsified exclusivity** — also InteractClickPick + `FUN_005995a0` (5 xrefs) |
| 10 | Uses map collision ctx `+0xe4a4` | Sibling cast | **Falsified** — only **`+0xe4e0`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HF null → 0 | High | False hits / crash |
| Above vs below split | High | Wrong march mode |
| Emerge-then-surface | High | Underground false hits |
| Bool return contract | High | Callers TEST AL |
| Caller maxSteps=400 | High | Wrong budget port |
| Not CastTerrainHeight | High | Wrong AutoCore API merge |
| Hit X/Z blend semantics | Medium | Sub-step accuracy only |
| Product name | Open | Registry rename risk |
| ECX=HF on sample (decompile-omitted) | High CF via sibling | Wrong this for 5a58c0 |

---

## 3. Cross-check against raw / live

```
if !*(map+0xe4e0) return 0;
out = start; pos = start; prevHf = 0; i = 0;
hf0 = SampleHF(start.x, start.z);
if (hf0 <= start.y) goto SURFACE;
// buried:
while (i < maxSteps) {
  pos += dir; out = pos; hf = SampleHF(pos.x, pos.z);
  if (hf < pos.y) goto SURFACE;  // emerged
  i++;
}
return 0;
SURFACE:
while (i < maxSteps) {
  pos += dir; out = pos; hf = SampleHF(pos.x, pos.z);
  if (pos.y <= hf) {
    t = |out.y - prevHf| / (|hf - pos.y| + |out.y - prevHf|);
    out.x += (pos.x - out.x) * t;  // may no-op if out==pos
    out.z += (pos.z - out.z) * t;
    return 1;
  }
  prevHf = hf; i++;
}
return 0;
```

Live force-decompile ≡ raw ≡ scaffold clean CF. Sibling `fn_004cfe60` shares HF offset + sample helper only.

---

## 4. Surviving contract for AutoCore

```
MarchDirToTerrain(map, start4, dir4, out4, maxSteps) -> bool
  Requires map heightfield (map+0xe4e0)
  Heightfield sample only — no collision filter / castRay
  Step budget is iteration count (retail callers: 400)
  Hit: probe Y at/below HF after a step; out holds hit-ish position
  Miss: false; out may be last step or start copy
  Consumers: drive tick secondary path, click-pick soft ray, FUN_005995a0
  Do NOT merge API with CastTerrainHeight (float Y + collision refine)
```

---

## 5. Open questions

1. Apply Ghidra rename only after product/string evidence (keep `_Inferred`).
2. Hit-block store order vs true sub-step XZ lerp (asm seal).
3. Should port snap `out.y = hfY` on hit? Retail body does not.
4. `FUN_005a58c0` dual not owned here.
5. Runtime multi-map HF golden.

**Verdict:** **accept-with-gaps** — adversarial attacks on “is CastTerrainHeight / castRay / float Y / meters range” all fail; name + hit-lerp precision remain open.
