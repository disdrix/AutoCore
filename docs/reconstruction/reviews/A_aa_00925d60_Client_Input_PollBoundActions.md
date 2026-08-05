# Review A (reconstruction fidelity): `aa_00925d60` Client_Input_PollBoundActions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925d60` |
| **VA** | `0x00925d60` |
| **Canonical name** | `Client_Input_PollBoundActions` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00925d60_Client_Input_PollBoundActions.md` |
| **System tag** | `input-drive-control` + **interact slice** → `interaction-activation` |
| **Verdict** | **accept-with-gaps** |
| **Scope this pass** | **Interact Activate edge residual only** (`DAT_00d1be62/63` → UseObject / 0x2055). Do **not** re-dual entire input map. |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_PollBoundActions.cpp` |
| Raw / annotated | `docs/reconstruction/raw/aa_00925d60_*` |
| Function record | `docs/reconstruction/functions/aa_00925d60_Client_Input_PollBoundActions.md` |
| System map | `docs/reconstruction/systems/interaction-activation.md` (flow D) |
| Fresh Ghidra | `decompile_function 0x00925d60` (2026-07-29); callees `0x009197a0`, `0x00925580`, `0x0058cd60` |
| Constants | `read_memory 0x00aaaca4` → `00 00 61 43` = **225.0f** |

**Purpose (full body, prior):** Frame poll of action **edge** flags (not held drive axes). QB / shift-QB / UI / chat / arena / interact.

**Purpose (this residual):** Bound-action **"Activate"** edge → world interact / UseObject (and exclusive early C2S `0x2055` gather hit).

---

## 2. Sealed interact Activate edge (High)

### 2.1 Edge gate (`LAB_0092788e` tail → body)

```
FUN_00925670(param_1);   // always; not Activate-specific

// Enter Activate body unless skip:
// skip if ( !(held&&edge) && !(cb&&cb(3)) )  OR  modal
// Edge clear: DAT_00d1be63 = 0 as part of gate evaluation when first clause false
//   (held@ DAT_00d1be62, edge@ DAT_00d1be63)
// Alternate trigger: (*DAT_00d1b624)(3) truthy when present
// Modal block: param_1[0x31e] != 0 → skip body
```

| Claim | Confidence | Evidence |
|---|---|---|
| Held/edge pair `DAT_00d1be62` / `DAT_00d1be63` | **High** | Decompile gate at Activate slice |
| Display name **"Activate"** at ActionMap `+0x4b9` | **High** (name) / **Probable** (slot↔DAT link) | `Client_InitActionDisplayNames` writes `s_Activate_00a8554c` @ `+0x4b9` |
| `DAT_00d1b624(3)` alternate input | **High** (call site) / **Tentative** (device meaning) | Same pattern as other edges with args 2/3 |
| `param_1[0x31e] != 0` blocks Activate | **High** | Same modal slot used across many edges |

### 2.2 Exclusive early path — C2S `0x2055` (not UseObject)

```
uStack_40/3c = 0xFFFFFFFF sentinel
// gather into uStack (decompiler arg-fold of FUN_0058cd60 + pos/range)
// imm range 0x41a00000 = 20.0f, mode bits include 1,6
if (uStack TFID != all-ones):
  FUN_00925580();   // packs opcode 0x2055 size 0x30; Client_SendSectorPacket
  goto LAB_00927be6;  // END Activate — no UseObject this frame
```

| Claim | Confidence | Notes |
|---|---|---|
| Hit TFID → `FUN_00925580` only | **High** | Exclusive `goto` past UseObject |
| `FUN_00925580` opcode **0x2055**, size **0x30** | **High** | Fresh decompile of `0x00925580` |
| Gather range **20.0f** on this sub-path | **High** | Imm `0x41a00000` |
| Full `FUN_0058cd60` ABI / mask semantics | **Tentative** | Large gather; call-site arg fold messy |

### 2.3 UseObject path — **~15f** residual (core seal)

Constants (static):

| Token | Value | Role |
|---|---|---|
| Imm `0x41700000` | **15.0f** | `Skill_GatherTargetsInArea` radius ×3; `FUN_009197a0(15.0f)` |
| `DAT_00aaaca4` | **225.0f** (`0x43610000`) | **Squared** max dist for `DAT_00d1d888` select; √225 = **15.0f** |
| Imm `0x41a00000` | **20.0f** | Early `0x2055` gather only (not UseObject) |
| Click path (peer) | **25.0f** `DAT_00aaa6fc` | `Client_InteractClickPickTarget` only — **not** this edge |

Control flow (sealed):

```
// Prefer current selection DAT_00d1d888 when:
//   non-null AND owner != local player AND dist² <= 225.0f
// else gather:

Skill_GatherTargetsInArea(..., radius=15.0f, mask args 1,3, ...)
  → Object_ResolveFromTFID
if null AND town flag *(DAT_00d1b644+0xf5):
  Skill_GatherTargetsInArea(..., 15.0f, mask 1,7,0x14, ...)
  → resolve

if resolved object piVar10:
  if piVar10[0x47] != 0:     // +0x11c dword  (0x47*4 = 0x11c)
    Client_SendUseObject();  // LAB_00927bdd
  else:
    fall through to FUN_009197a0 path

// LAB_00927b2a — proximity / list helper
pv = FUN_009197a0(15.0f);
if pv == null:
  Skill_GatherTargetsInArea(..., 15.0f, mask 1,8, ...)  // LAB_00927b57 fallback
  pv = resolve
else:
  if *(pv+0x11c) != 0: Client_SendUseObject();  // exclusive
  else if FUN_00524520(pv) == 0: goto fallback gather (mask 8)
// after resolve / fallback:
if pv != null && FUN_00524520(pv) != 0:
  Client_SendUseObject_IfInteractable();
```

| Claim | Confidence | Notes |
|---|---|---|
| Key-Activate UseObject gather radius **15.0f** | **High** | Imm + `aaaca4`=225 seal |
| Selected-target max range also **15.0f** (via 225²) | **High** | `read_memory` |
| `obj+0x11c` / `piVar10[0x47]` → unconditional `Client_SendUseObject` | **High** | Same flag as pick hub |
| Else objective match `FUN_00524520` → `Client_SendUseObject_IfInteractable` | **High** | Double call sites (gate + send) |
| SendUseObject and IfInteractable **mutually exclusive** this edge | **High** | Separate branches; no fall-through dual send |
| Early `0x2055` exclusive vs UseObject | **High** | `goto LAB_00927be6` |
| `FUN_009197a0` = nearest in-range interactive from world list / auto-patrol | **Probable** | Body walks hash + dist² ≤ r² |
| Gather masks `(1,3)` / `(1,7,0x14)` / `(1,8)` taxonomy | **Tentative** | Shared residual with pick hub |

### 2.4 What this edge is **not**

| Non-claim | Why |
|---|---|
| Not DriveControlTick thr/steer/HB | Separate VA `0x009223b0` |
| Not click pick hub | `Client_InteractClickPickTarget` `0x009247b0`; 25f gate |
| Not QB ActivateSlot | Different DAT cascade earlier in body |
| Not full ActionMap dual | Explicitly out of scope this pass |

---

## 3. Confidence table (updated)

| Claim | Confidence | Notes |
|---|---|---|
| Edge-triggered poll (not continuous drive) | **High** | Plate WI-INP-004 |
| QB / shift-QB ActivateSlot | **High** | Prior dual; untouched this pass |
| **Activate edge → 15f UseObject / IfInteractable** | **High** | Fresh decompile + constants |
| **Activate edge → exclusive 0x2055 first** | **High** | `FUN_00925580` |
| Edge pattern held/edge adjacent bytes | **High** | `be62`/`be63` |
| Full UI edge DAT map | **Tentative** | Out of residual scope |
| `DAT_00d1b624` device class | **Tentative** | Open |

---

## 4. Control flow: clean ≡ raw (Activate slice)

| Stage | Match |
|---|---|
| Gate `be62`/`be63` + `b624(3)` + modal | Yes |
| `0058cd60` → `00925580` early out | Yes |
| `d1d888` / gather 15f / `009197a0` / `+0x11c` / `00524520` | Yes |
| SendUseObject vs IfInteractable branch split | Yes |

---

## 5. Gaps (residual after this pass)

1. Exact ActionMap slot index / DIK default for Activate ↔ `DAT_00d1be62` base (name sealed; table math open).
2. `FUN_0058cd60` full param map + what object class yields `0x2055` vs fall-through.
3. Gather mask taxonomy for modes 3 / 7+0x14 / 8 (shared pick residual).
4. Runtime wire: one keypress → only `0x2055` **or** only `0x2072` (static exclusive).
5. Full body UI edge catalog (explicitly not this residual).

**Verdict:** **accept-with-gaps** — interact Activate **15f** dual residual **sealed at High** for send branching + ranges; gather-mask / 0x2055 class residual remain.
