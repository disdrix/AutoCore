# Review A (reconstruction fidelity): `aa_0082fe20` UI_InteractionMenu_PopulateTargetButtons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fe20` |
| **VA** | `0x0082fe20`–`0x0082ff3f` exclusive |
| **Body size** | **287 B** (`0x11F`) |
| **Canonical name** | `UI_InteractionMenu_PopulateTargetButtons_Inferred` |
| **Ghidra name** | `FUN_0082fe20` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0082fe20_UI_InteractionMenu_PopulateTargetButtons_Inferred.md` |
| **System** | interaction menu / social UI |
| **Agent** | WQ9E-D OWN-ONLY dual |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, `read_memory`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/pack order/child convoy dual sealed; product host class + vtbl English open |

---

## 1. Purpose

**Interaction-menu target social button populate.** For an active menu host (`+0x4C0`), rebuild the popup shell, resolve the target TFID at host `+0x578`, gate self/local/affinity, then call the seven social button packs in one of two orders. Parent of dualed `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred`.

```c
// __thiscall; ECX = menu host*; ret 0
void UI_InteractionMenu_PopulateTargetButtons_Inferred(MenuHost* menu);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` @ `0x0082fe20` |
| Body span | `get_function_by_address` `0082fe20`–`0082ff3e` + `read_memory` + pad `CC` |
| Entry bytes | `56 8B F1` (ESI=ECX host) |
| Call targets | relative `E8` → `0082d2b0`, packs, `0082fb30`×2, `0090d400`×2, resolve |
| Child dual | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`aa_0082fb30`) |
| Sibling strings | Tell / Ignore / Friends / Trade / Clan / Convoy via pack decompiles |
| Xref | DATA only `0x00a720e0` (vtbl) |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 287 B / pad `CC` | **Confirmed** | meta + memory |
| ECX = menu host; `ret 0` | **Confirmed** | entry + epilogues `C3` |
| Gate `+0x4C0` | **Confirmed** | `cmp [esi+0x4C0],0` |
| TFID @ `+0x578` | **Confirmed** | `lea edx,[esi+0x578]` |
| Local `DAT_00d1b6d8` | **Confirmed** | immediates + peer duals |
| Shell rebuild `FUN_0082d2b0` | **Confirmed** | first call |
| Dual pack orders via `vtbl+0x478` | **Confirmed** | decomp + call-site order |
| Convoy child ×2 sites | **Confirmed** | `0x0082fec7`, `0x0082ff1b` |
| Vtbl method (DATA xref only) | **Confirmed** | xrefs |
| Product menu class / MSVC name | **Inferred** | no RTTI on VA |
| `vtbl+0x210` / `+0x298` English | **Open** | structural only |

---

## 4. Control flow

```
if host+0x4C0 == 0: return
FUN_0082d2b0(host)
if !local || !resolve(TFID@+0x578) || local.vtbl+0x298(target):
  maybe FUN_0090d400 if host+0x2B0; return
owner = target.vtbl+0x210(0)
if !owner || owner == local:
  maybe FUN_0090d400; return
if host.vtbl+0x478() == 0:
  Ignore, Friends, Tell, Trade, Clan, Convoy, Name
else:
  Name, Convoy, Clan, Trade, Tell, Friends, Ignore
```

---

## 5. Gaps (acceptable)

1. Product class / MSVC name for menu host.
2. English for `+0x4C0`, `+0x2B0`, affinity/owner vtbl slots, order flag.
3. Dual of sibling packs / shell rebuild / close path (not OWN).
4. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.
