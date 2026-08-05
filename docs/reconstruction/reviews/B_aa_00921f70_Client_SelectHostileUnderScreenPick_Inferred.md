# Review B (skeptical / adversarial): `aa_00921f70` Client_SelectHostileUnderScreenPick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-Q) |
| **Counterpart** | `reviews/A_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is ally soft-target (mode 1) | **Falsified** — gather mode literal **2** (hostile dual table) |
| 2 | Fixed range 40 always | **Falsified** — `range = dist*0.015*25` then min with 40 |
| 3 | Multi-target tab cycle | **Falsified** — `maxTargets=1` |
| 4 | Runs even when char busy (`+0x4f1`) | **Falsified** — early return 0 |
| 5 | Returns 0 when no target found | **Falsified** — pick path returns **1** after select(0) clear |
| 6 | Constants are 1.0 / 100 (guess) | **Falsified** — bytes 0.015 / 25 / 40 |
| 7 | Clean invents mouse click raycast physics | **Falsified** — uses existing unproject + gather only |
| 8 | Many call sites | **Falsified** — single CODE xref `0x00922262` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hostile mode 2 | **High** | Ally/hostile selection bug |
| Range formula | **High** | Wrong pick radius |
| maxTargets 1 | **High** | Multi-select behavior wrong |
| Gate `+0x4f1` | **High** | Select while busy |
| Return 1 after clear | **High** | Caller success semantics |
| Product binding name | Low | Docs only |
| Parent UI function | Medium | Who invokes pick residual |

---

## 3. Cross-check against raw + bytes

```
if !char || char[+0x4f1]: return 0
unproject(screen) → origin, dir
t = (oy - height(ox,oz)) / |dirY|
hit = origin + dir*t
range = min( |hit-ref| * 0.015 * 25 , 40 )
GatherTargets(hostile mode2, max1, range) → tfid
select(resolve(tfid) or null)
return 1
```

`read_memory` LE floats match formula. Mode/maxTargets match `Skill_GatherTargetsInArea` caller table entry for this VA.

---

## 4. Surviving contract for AutoCore

```csharp
// Port sketch — Client_SelectHostileUnderScreenPick_Inferred
bool TrySelectHostileUnderScreenPick(ClientState client)
{
    var ch = client.LocalCharacter;
    if (ch == null || ch.BusyFlag_4f1) return false;

    var (origin, dir) = client.GfxView.Unproject(client.ScreenX, client.ScreenY);
    float h = HeightAt(origin.X, origin.Z);
    float t = (origin.Y - h) / Math.Abs(dir.Y);
    var hit = origin + dir * t;
    float dist = (hit - client.RefPos).Length;
    float range = Math.Min(dist * 0.015f * 25f, 40f);

    var tfid = GatherHostiles(hit, range, max: 1);
    if (tfid.IsNull) client.SelectTarget(null);
    else {
        var obj = Resolve(tfid);
        if (obj != null) { client.SelectTarget(obj); return true; }
    }
    return true; // retail returns 1 even after clear / unresolved
}
```

Do **not** use mode 1/3 here; do **not** expand maxTargets without new evidence.

---

## 5. Open questions

1. Input action / key that reaches site `0x00922262`.
2. Whether `DAT_00d17944` is camera or avatar for distance (affects feel, not CF).
3. `FUN_004cd220` product semantics (terrain height vs plane).

**Verdict:** **accept-with-gaps**
