# Review B (skeptical / adversarial): `aa_0089c330` UI_RefinePanel_SyncQtyControls_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089c330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0089c330_UI_RefinePanel_SyncQtyControls_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `void FUN(void)` no this | Callers force `ESI=EDI`; body reads `unaff_ESI+…` | **Falsified** — ESI this |
| 2 | Always enables all buttons | Zero avail hides all; qty==1 hides low; qty==max hides high | **Falsified** |
| 3 | Writes catalog / inventory model | Only host qty + widget vtbls + `FUN_0089bf50` | **Falsified** as model write |
| 4 | Decompiler `goto` means wrong clamp | Clamp block before widgets sets floor 1 / ceil avail | **Sealed** clamp |
| 5 | Standalone entry point | Only `FUN_0089c6c0` (8 sites) | **Falsified** |
| 6 | ECX thiscall | No `mov ecx`; ESI custom | **Falsified** as ECX thiscall |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI = refine host | **High** | Wrong ABI |
| `+0x5ec` coid / `+0x524` qty | **High** | Desync spinner |
| Hide-all when avail 0 | **High** | Ghost buttons |
| Pair visibility vs 1 and max | **High** | Stuck steppers |
| Exact button product roles | **Tentative** | UI chrome only |
| `FUN_0089bf50` English | **Open** | Residual refresh |

---

## 3. Surviving contract

```c
// custom: ESI = RefineUiHost*
void UI_RefinePanel_SyncQtyControls(void /*ESI this*/);
```

- Looks up `host+0x5ec` in clone hash; `FUN_00522060` → available stack.
- Clamps `host+0x524`; drives text `+0x608` and four control widgets.
- Always ends with `FUN_0089bf50`.

---

## 4. Verdict

**accept-with-gaps** — adversarial seals ESI ABI and hide/show policy against decompiler noise.
