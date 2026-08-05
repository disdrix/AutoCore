# Review B (skeptical / adversarial): `aa_009247b0` Client_InteractClickPickTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_009247b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen 25f/0.015f; prior refresh same day / 2026-07-23) |
| **Counterpart** | `reviews/A_aa_009247b0_Client_InteractClickPickTarget.md` |
| **Residual seal** | `reviews/a_009247b0.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** on UseObject + constant table + matcher ECX; dual-send **CF sealed / wire open**; helper English **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Every click sends UseObject | **Falsified** — requires pick resolve + (`IfInteractable` matchers **or** (`+0x11c` && dist≤25f)); many early returns |
| 2 | Client is sole range authority | **Falsified as sole** — plate + product re-gate ~30f; client 25.0f is **local** gate only |
| 3 | GatherTargets always returns interactables | **Overstated** — soft A **mode 3** (living types); soft B **mode 2** (hostile); A2 sibling `FUN_0058cd60`; empty TFID `lo&hi==−1` |
| 4 | Clean is fully human-refined for all FUN_* | **Overstated** — stages labeled; helper product names still FUN_* |
| 5 | Self/vehicle click always UseObject | **Falsified** — stage 4 returns 1 without store when `(char)param_4==0` |
| 6 | Special mode `DAT_00d1a8da` also UseObjects | **Falsified** — select via `FUN_0093e120` only, return 1 |
| 7 | Type-4 switch is UseObject | **Falsified** — `0x205D` QuestItemPickup size `0x10`, not `0x2072` |
| 8 | Only one UseObject path per click | **CF falsified exclusivity** — IfInteractable @ stage 5 then SendUseObject @ stage 7 can both run; wire dump still open |
| 9 | Soft path (`param_3==0`) never UseObjects | **Falsified as absolute** — stage 5–7 still run after soft gather if object found |
| 10 | 25f is also gather-only constant | **Partial truth** — same DAT: UseObject gate **and** gather caps **and** path-B scale (`*25`); path B **cap** is 40f |
| 11 | Matcher ECX is the world object | **Falsified** — asm: ECX=`DAT_00d1b6d8` character; stack = object |
| 12 | “1,3 / 1,2” are bitmasks | **Falsified** — `(maxTargets, gatherMode)` with modes 3 and 2 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UseObject distance gate (25.0f + `+0x11c`) | **Confirmed** | Exploit / stuck interact / false ports |
| 0.015f post-dist gather scale | **Confirmed** | Wrong soft-pick radius |
| IfInteractable call when matchers non-zero | **Confirmed** | Missed mission interact |
| Matcher ECX = player character global | **Confirmed** | Wrong thiscall port |
| Dual UseObject on one click (CF) | **High** static / wire open | Double server handle if both fire |
| Selection store slots | **High** (CF) / **Probable** (product field names) | Wrong target UI |
| Type-4 = `0x205D` | **High** | Wrong opcode in ports |
| Gather mode numbers 3 / 2 | **High** | Wrong soft-pick class |
| Full path coverage / input modes | **Tentative** | Missed DAT modes |
| Gather / helper **English** names | **Tentative** | Doc mislabel |
| Runtime click capture | **Open** | Doc vs live |

---

## 3. Cross-check against raw / live

Sealed UseObject tail (stage 7) — asm @ `0x00924ed1`…`0x00924ee5`:

```
if obj+0x11c != 0:
  d = √||obj.pos - playerBody.pos||   // player via vtbl+0x1a0
  FCOMIP 25.0f vs d; JC skip when 25 < d
  Client_SendUseObject()             // this = client EBX
```

Sealed IfInteractable (stage 5) — asm @ `0x00924d8c`…`0x00924db6`:

```
store select [EBX+0xd24], [EBX+0x758]
ECX = DAT_00d1b6d8; PUSH obj; CALL 005245d0
if zero: ECX = DAT_00d1b6d8; PUSH select; CALL 00524520
if either non-zero: Client_SendUseObject_IfInteractable()
FUN_0093e120(select)
```

Constants verified by `read_memory` (not plate-only); 0.015 exact float rep:

| DAT | Bytes | Float | Dual residual role |
|-----|-------|------:|--------------------|
| `00aaa6fc` | `00 00 c8 41` | **25.0** | UseObject gate + gather cap A + scale B |
| `00aaacbc` | `8f c2 75 3c` | **0.015** | post-`0040d020` scale (“15f” in task shorthand) |
| `00a110d8` | `00 00 20 41` | 10.0 | soft A radius mult |
| `00aaa688` | `00 00 a0 40` | 5.0 | soft A2 radius mult |
| `00a1109c` | `00 00 20 42` | 40.0 | soft B radius cap |

Case 4 imm `1.16098e-41` → bits **`0x205d`** = `GameOpcode.QuestItemPickup` — do **not** document as UseObject.

---

## 4. Surviving contract for AutoCore

```
InteractClickPickTarget(ctrl, mousePacked, softOrCommit, filterFlag):
  if blocked: return 0
  resolve world pick (primary / ray / gather / special modes)
  if filterFlag.low==0 and pick in {self, vehicle}: return 1
  store selection on client
  if pick and (matcher_d0(pick) or matcher_520(pick)):
    Client_SendUseObject_IfInteractable()   // may send 0x2072
  if pick and pick.interactFlag(+0x11c) and dist(player,pick) <= 25.0f:
    Client_SendUseObject()                  // may send 0x2072
  type switch may send 0x205D (type 4) or other non-UseObject actions
  return 1

Server MUST re-validate UseObject range (~30f product) and objective authority.
Do NOT treat client 25f as server max.
Do NOT unify SendUseObject objective −1 with IfInteractable objective 0.
```

---

## 5. Falsification notes vs prior dual

| Prior residual | This pass (strengthen) |
|---|---|
| Exact float of `DAT_00aaa6fc` open | **Closed** = 25.0f (Confirmed + FCOMIP) |
| 0.015 scale approximate only | **Closed** = `8f c2 75 3c` = 0.015f Confirmed |
| Type-4 float imm unexplained | **Closed** = opcode `0x205D` |
| System `unknown` | → `interaction-activation` |
| Dual shallow on gather scales | **Closed table** 0.015 / 10 / 5 / 25 / 40 |
| “Masks” 1,3 / 1,2 | **Reframed** maxTargets+gatherMode (3 living / 2 hostile) |
| Matcher ECX open | **Closed** = `DAT_00d1b6d8` |
| Dual-send same click | CF **sealed possible**; wire still open |

---

## 6. Open questions

1. Wire dump: does production dual-fire IfInteractable + SendUseObject on one click?
2. ~~Character ECX into `FUN_00524520`~~ — **closed**.
3. Product English for pick helpers + `FUN_0058cd60` mode-5 path.
4. Soft path (`DAT_00d1a860` / `param_3=0`) product UX name (hover vs soft-commit).
5. Runtime mission deliver vs type-4 pickup split.

**Verdict:** Safe **UseObject gate contract** for ports (**25f** + `+0x11c`; separate IfInteractable; matcher this = character). Soft gather radii use **0.015** scale. Do **not** claim complete helper English taxonomy or wire-proven single-send exclusivity. **accept-with-gaps.**
