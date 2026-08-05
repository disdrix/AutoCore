# Review B (skeptical / adversarial): `Client_Input_PollBoundActions` @ `0x00925d60`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925d60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00925d60_Client_Input_PollBoundActions.md` |
| **Verdict** | **accept-with-gaps** |
| **Scope this pass** | **Interact Activate edge residual only** — refuse re-dual of full input map |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sets thr/steer/handbrake axes | Body is edge cascade; drive is `DriveControlTick` | **Falsified** |
| 2 | Only quickbar | Many UI/chat/interact edges | **Falsified** |
| 3 | Produces edges from raw keys | Consumes OnKeyDown edges | **Falsified** |
| 4 | Activate always sends UseObject `0x2072` | First hit path is `FUN_00925580` → **0x2055** exclusive | **Falsified as absolute** |
| 5 | Activate uses click distance **25f** | Key path imm **15.0f** + `aaaca4`=**225** (15²); 25f is pick-only | **Falsified for this edge** |
| 6 | One press can dual-send UseObject + IfInteractable | Branches exclusive; `+0x11c` → Send only; match → IfInteractable only | **Falsified (static)** |
| 7 | System-map flow D “flag then else match” is complete | Omits `0x2055` early path, selection `d1d888`, multi-gather masks, `009197a0` | **Partial — map corrected this pass** |
| 8 | `piVar10[0x47]` is unrelated field | `0x47*4 = 0x11c` matches `*(obj+0x11c)` path | **Attack fails** — same flag |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| QB edge → ActivateSlot | High | Skills dead (prior) |
| Edge vs held separation | High | Sticky fire |
| **Activate held/edge `be62`/`be63`** | **High** | Wrong bind |
| **15.0f UseObject gather / select** | **High** | Server range mismatch vs client key |
| **`+0x11c` → SendUseObject** | **High** | Wrong sender |
| **`00524520` → IfInteractable** | **High** | Mission interact dead |
| **0x2055 exclusive early** | **High** | Drop legitimate vehicle/special use |
| `0x2055` product meaning | **Tentative** | Mis-name packet |
| Gather mask taxonomy | **Tentative** | Miss class of targets |
| Full UI edge set | **Tentative** | Out of residual scope |
| Body freshness | **High** this slice | Fresh 2026-07-29 decompile |

---

## 3. Cross-check against raw / Ghidra

```
Activate residual (sealed):
  trigger: (be62 && be63) || b624(3); clear be63; block if param_1[0x31e]
  if FUN_0058cd60-class gather TFID valid:
      FUN_00925580()  // C2S 0x2055 / 0x30
      end
  prefer DAT_00d1d888 if not self and dist² ≤ 225
  else Skill_GatherTargetsInArea r=15 (masks 3 / town 7+0x14)
  if obj+0x11c: Client_SendUseObject()
  else FUN_009197a0(15) / mask-8 fallback
       if +0x11c: SendUseObject
       elif FUN_00524520: Client_SendUseObject_IfInteractable()
```

Raw/annotated/clean CF for this slice match; constants verified via `read_memory` (`aaaca4`) and immediates (`41700000`, `41a00000`).

---

## 4. Surviving contract for AutoCore (Activate residual)

```
OnActivateEdge (key / device cb arg 3):
  // NOT the 25f click path
  try special gather @ 20f → maybe C2S 0x2055; if hit, stop
  resolve target within 15f (selection or gather / nearest helper)
  if interact flag obj+0x11c:
    Client_SendUseObject()           // 0x2072, objective −1 path
  else if CVOGCharacter_FindActiveObjectiveIdForInteract(obj):
    Client_SendUseObject_IfInteractable()  // 0x2072 gated
  // never both UseObject senders on same edge evaluation
```

Server-side: key interact range product should treat **~15f** client gather as authoritative intent for bind Activate (click remains **25f** client / ~**30f** server docs).

---

## 5. Open questions

1. What world objects make `0x2055` fire (vehicle enter? special prop?) — `FUN_0058cd60` mode 6 residual.
2. Confirm ActionMap slot index that owns `DAT_00d1be62` (name **"Activate"** sealed at display table).
3. Wire dump: Activate on NPC with objective → only `0x2072` IfInteractable layout (id≠−1).
4. Wire dump: Activate on `+0x11c` prop → SendUseObject layout (id −1 possible).
5. Optional: force_decompile full body for non-interact sections (out of residual).

**Verdict:** **accept-with-gaps** — adversarial checks **raise** Activate 15f / exclusive-send confidence; residual gaps are gather-class + product naming of `0x2055`, not the UseObject branch skeleton.
