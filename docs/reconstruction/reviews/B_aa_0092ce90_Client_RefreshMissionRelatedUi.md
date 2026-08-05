# Review B (skeptical / adversarial): `Client_RefreshMissionRelatedUi` @ `0x0092ce90`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0092ce90_Client_RefreshMissionRelatedUi.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Schedules `EvaluatePendingObjectives` | Body has zero named calls; no hash walk | **Falsified** |
| 2 | Completes missions / objectives | No CompleteObjective / 0x2070 path | **Falsified** |
| 3 | Writes objective slot floats | No packet, no state node access | **Falsified** |
| 4 | Touches only journal at `+0x1030` | Body uses **`+0x107c`** and **`+0x10b8` only** | **Falsified** |
| 5 | Dirty `+0x520` is “dword index 0x148” confusion | Live bytes: `C6 86 20 05 00 00 01` → **byte @ +0x520** | **Sealed High** |
| 6 | `+0x448` is always “hide” (from Hide sibling plate) | Same offset used as refresh by RecvObjectiveState / RefreshOpenMissionUiWindows when panel visible; dual labels conflict | **Open product name**; role still UI-only vcall |
| 7 | Context is stack `this` / ECX client | Prologue uses **EDI** as client base; ECX is **widget** | **EDI client sealed** |
| 8 | Alias of `Client_RefreshOpenMissionUiWindows` | Different body: multi-slot named refreshes vs two fixed slots + dirty | **Distinct** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf UI-only CF | **High** | False mission-complete port |
| Dual panel offsets `0x107c` / `0x10b8` | **High** | Wrong HUD sync |
| Dirty `@+0x520` | **High** | Missed deferred panel |
| `+0xd0` / `+0x3d8` dual gate | **High** | Spurious vcalls / skip |
| `+0x448` product semantics | **Medium** | Hide vs repaint confusion in ports |
| Secondary panel identity | **Medium** | Wrong UI surface |
| Role name `Client_RefreshMissionRelatedUi` | **Medium** | PDB may differ |

---

## 3. Cross-check against raw + machine

```text
PUSH ESI
ESI = [EDI+0x107c]; if ESI:
  if thiscall vtbl+0xD0 (ECX=ESI): if vtbl+0x3D8: vtbl+0x448
ESI = [EDI+0x10B8]; if ESI:
  if vtbl+0xD0: if vtbl+0x3D8: [ESI+0x520] = 1
POP ESI; RET
```

Matches frozen raw `aa_0092ce90_FUN_0092ce90.md` and live `decompile_function` 2026-07-29. No CF drift.

Sibling `0x0092ce50` (Hide): **ESI** client, only `+0x107c`, no `+0xd0`, ends with `+0x448` **and** `+0x34c`. Not interchangeable with this function.

---

## 4. Surviving contract for AutoCore

```text
Client_RefreshMissionRelatedUi(client in EDI):
  // pure client UI; no packets; no objective completion
  if missionUiRoot = client[0x107c]:
    if IsReady(+0xd0) and IsVisible(+0x3d8):
      VirtualRefreshOrUpdate(+0x448)   // product name open
  if secondaryPanel = client[0x10b8]:
    if IsReady(+0xd0) and IsVisible(+0x3d8):
      secondaryPanel.dirty[+0x520] = 1

Call after local mutations that may change mission-related HUD:
  RecvObjectiveState (0x2071), inventory add/drop, and peers that also
  call Client_RefreshOpenMissionUiWindows.
Do NOT treat as EvaluatePending or CompleteObjective substitute.
```

---

## 5. Open questions

1. Class / RTTI of `+0x107c` and `+0x10b8` widgets.
2. Resolve `vtbl+0x448` product name across Hide vs Refresh call sites (shared base method?).
3. Who polls `+0x520` dirty and what it redraws.
4. Whether any caller expects EDI already = client without reloading (calling convention glue).
5. Runtime verification under live mission + inventory mutations.

**Verdict:** Adversarial pass confirms **UI refresh leaf only**. **accept-with-gaps** on product naming / `+0x448` semantics; completion/eval claims stay dead.
