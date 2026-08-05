# Review B (skeptical / adversarial): `aa_004b8dc0` FUN_004b8dc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8dc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b8dc0_FUN_004b8dc0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always runs activate+deactivate | `if (flag) { 7e50; 6fc0; return; }` then teardown | **Falsified** — **mutually exclusive** branches |
| 2 | Unconditionally stores flag | Leading `cmp al,[esi+0xB]; jz skip` | **Falsified** — **edge-triggered** |
| 3 | Single list | Separate heads `+0x1E0`, `+0x204`, `+0x1EC`, `+0x1F8` | **Falsified** — **four** list roles |
| 4 | `param_3` unused | Pushed into `FUN_005bbb90` path only | **Partially** — used on list1 notify; **not** teardown |
| 5 | `+0x1F8` always walked on off | Gated by `this+0x1FC != 0` | **Confirmed gate** |
| 6 | Mission-complete only | Callers include weapon fire `0056d160` | **Falsify exclusive mission** — host is **shared FX** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Edge trigger on `+0x0B` | **High** | Spurious double-play |
| Activate vs deactivate split | **High** | Leaked FX / missed stop |
| List head offsets | **High** | Walk wrong memory |
| Payload at `node[2]` for teardown lists | **High** | Wrong object stopped |
| Semantic names of stop callees | **Medium** | Ghidra naming collision risk |
| `param_3` product meaning | **Low** | Often 0 from weapon path |

---

## 3. Cross-check against raw + bytes

```
raw CF:
  if (param_2 == *(this+0xb)) return;
  *(this+0xb) = param_2;
  walk +0x1e0 → 005bbb90(flag, param_3);
  walk +0x204 → 0058e930(flag);
  if (flag) { 004b7e50(0..); 004b6fc0(); return; }
  walk +0x1ec → stop pair on node[2] fields 0x120/124/128;
  if (+0x1fc) walk +0x1f8 → 00720d40(p,1); 007203b0(p,1);

entry bytes:
  8A442404 5356 8BF1 3A460B 57 0F84F0000000 88460B
  8B86E0010000 ... 8B8604020000 ... 807E0B00 7430
  (activate: push zeros + call 004b7e50)

≡ sealed. Sibling dual 004b7e50 owns process-list details.
```

---

## 4. Surviving contract for AutoCore

```csharp
void SpecialFxHost_SetActive(Host h, bool on, object? notifyCtx = null)
{
    if (on == h.ActiveBit /*+0x0B*/) return;
    h.ActiveBit = on;
    foreach (var n in h.List_1E0) NotifyA(n, on, notifyCtx);
    foreach (var n in h.List_204) NotifyB(n, on);
    if (on)
    {
        SpecialFxHost_ProcessAttachedList(h, forceFlag: false, target: null, nameFilter: null, xyz: default);
        SpecialFxHost_PostActivate(h); // FUN_004b6fc0
        return;
    }
    foreach (var n in h.List_1EC) StopPrimary(n.Payload);
    if (h.Gate_1FC != 0)
        foreach (var n in h.List_1F8) StopSecondary(n.Payload, flag: 1);
}
```

- Client cosmetics / feedback; server need not replicate lists for authority.
- Weapon fire should call **on=true** when starting sustained FX and **on=false** when ending (matches `FUN_0056d160`).

---

## 5. Open questions

1. Node types for each of the four lists.
2. Whether `Client_GetMissionCompleteAudioTable` symbol is correct at stop sites or a decompiler overload artifact.
3. Full `FUN_004b6fc0` contract (not owned).
4. Runtime confirmation.

**Verdict:** **accept**
