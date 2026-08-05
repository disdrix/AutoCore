# Review B (skeptical / adversarial): `aa_004b6fc0` NDSpecialFX_RequestPlayAudioList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6fc0` |
| **VA** | `0x004b6fc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004b6fc0_NDSpecialFX_RequestPlayAudioList_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is mission-complete audio only | Scaffold name `Mission_Requesting_play_s_*` | **Falsified as mission-only** — host is NDSpecialFX list `+0x1F8`; called from weapon/FX activate + weather tick |
| 2 | Same as deactivate stop walk | Both touch `+0x1F8` | **Distinct** — stop path in `004b8dc0` uses `00720d40(p,1)` + `007203b0`; this uses `00720670` + `"Requesting play"` |
| 3 | Free function / no host | No stack args | **Falsified** — ECX host; list at `this+0x1F8` |
| 4 | Network packet emitter | Log looks like RPC | **Falsified** — leaf list walk + audio helpers + debug print |
| 5 | Copies payload back into heap | `0x32` dword copy | **Falsified as write-back** — destination is stack scratch only |
| 6 | Product name known | string evidence | **Holds as false** — `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List offsets `+0x1F8` / gate `+0x1FC` | **High** | Wrong FX subsystem wire |
| Play vs stop polarity | **High** | Activate/deactivate inversion |
| Payload size `0xC8` | **High** | Buffer over-read on port |
| Exact audio engine API | **Probable** | Cosmetic/audio residual only |
| `%s` points at name inside payload | **Probable** | Log-only |

---

## 3. Cross-check against raw / live

```
if (fx->count_or_flag@+0x1FC == 0) return;
for (n = *list@+0x1F8; n != list; n = *n) {
  p = n[2];
  stack_copy_0xC8(p);
  FUN_00720d40(...);
  FUN_00720670(...);
  FUN_007a4480(..., "Requesting play %s\n", p);
}
```

Live decompile ≡ raw ≡ clean scaffold CF. Call sites: `004b8e49`, `00556415`, `0055643c`.

---

## 4. Surviving contract for AutoCore

```
// On NDSpecialFX host activate (after attached-FX process 004b7e50):
NDSpecialFX_RequestPlayAudioList_Inferred(fx);
// Precondition meaningful: +0x1FC != 0 and +0x1F8 list populated (clone path 004a0b90)
```

---

## 5. Open questions

1. Whether `00720d40`/`00720670` consume stack copy or original `p` (decompiler elision).
2. Name field offset inside the 0xC8 pod.

**Verdict:** **accept-with-gaps**
