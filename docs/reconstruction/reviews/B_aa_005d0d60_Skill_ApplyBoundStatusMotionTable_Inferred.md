# Review B (skeptical / adversarial): `aa_005d0d60` Skill_ApplyBoundStatusMotionTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d0d60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005d0d60_Skill_ApplyBoundStatusMotionTable_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `__fastcall` / zero stack args (decomp risk) | Epilogue `RET 4`; compare uses `[EBP+8]`; caller JMP with stack skillId | **Falsified** zero-arg |
| 2 | Zero-arg void apply only | skillId compared to table key; modes dispatched | **Falsified** |
| 3 | Always applies phys (impulse/handbrake) | Gated by duration≠0 **and** entry+0x0a; early outs | **Falsified** always-phys |
| 4 | Impulse is full velocity vector | Bytes zero X after load; keep Y@+0x44 only | **Sealed** Y-only |
| 5 | Scaffold “RecvSkillStatusEffect” is product name | No strings/RTTI; structural name from CF | **Falsified** as proven product English |
| 6 | Multiple external callers | analyze: sole xref `004c2f2a` | **Survives** single-caller |
| 7 | Mode args use doubles | Immediates `0x3dcccccd` / `0xbf800000` float bits | **Falsified** double claim |
| 8 | Structural name wrong | Matches sealed 004c2f20 dual + table/mode body | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + skillId + RET 4 | **High** | Stack smash / wrong skill |
| Table stride 0x18 | **High** | Miss entries |
| End-time `*0.001` | **High** | Wrong duration units |
| Mode map | **High** | Wrong motion channel |
| Heading early-return epsilon | **High** value / **Medium** product role | Spurious rotations |
| Mode code product meaning | **Open** | Wrong server enum mapping |

---

## 3. Cross-check against raw / bytes

```
raw: thiscall; tree scan 0x18; time=(tick+dur)*0.001; flags; switch mode→vtbl+0x64
bytes: 8b f9; 8b 4d 08 skill; imul/div 0x18; mul 0xa0f72c; c2 04 00
caller 004c2f20: mov ecx,[ecx+0x1fc]; test; jz ret4; jmp 005d0d60
```

Clean ≡ raw ≡ decompile CF. Machine ABI sealed beyond decompiler `undefined` signature.

---

## 4. Surviving contract for AutoCore

```csharp
// Status/motion table apply — companion to Skill_ApplyBoundStatusMotionIfPresent gate.
void ApplyBoundStatusMotionTable(Controller ctl, int skillId)
{
    if (ctl.Spawn == null) return;
    var entry = FindEntry(ctl.Entity.MotionTable, skillId); // stride 24
    if (entry == null) return;
    ctl.EndTimeSec = (ClientTickMs + entry.DurationMs) * 0.001f;
    if (entry.DurationMs != 0) {
        if (entry.DoPhys) {
            entity.Flag305 = true;
            // optional: clear 304, impulse (0, physY, 0, 0), handbrake, heading
        }
        entity.Flag306 = true;
    }
    switch (entry.Mode) {
        case 1: entity.ApplyMotion(3,  0.1f, 1, -1f); break;
        case 2: entity.ApplyMotion(4,  0.1f, 1, -1f); break;
        case 3: entity.ApplyMotion(16, 0.1f, 1, -1f); break;
        case 4: entity.ApplyMotion(17, 0.1f, 1, -1f); break;
    }
}
```

**Port traps to reject:**

- Calling without stack skillId / using fastcall only.
- Stride ≠ 24 or key at wrong offset.
- Always handbrake/impulse without entry+0x0a gate.
- Duration stored as ms without `*0.001` to seconds.

---

## 5. Residual gaps (do not block seal)

1. Product English for modes 3/4/16/17 and flags +0x304..306.
2. Exact type of table tree at `+0x520`.
3. Runtime capture of entry contents from live skill apply.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break thiscall/RET4, skill-id table match, end-time formula, mode map, or Y-impulse gate. Main falsifications are zero-arg/fastcall myths and always-phys. Gaps are product English only.
