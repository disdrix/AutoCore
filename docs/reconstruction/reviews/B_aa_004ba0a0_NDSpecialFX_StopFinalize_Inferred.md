# Review B (skeptical / adversarial): `NDSpecialFX_StopFinalize_Inferred` / `FUN_004ba0a0` @ `0x004ba0a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba0a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-D) |
| **Counterpart** | `reviews/A_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** DeactivateClear | **Falsified** — different body/callees; HostTick uses `FUN_004b7150` for deactivate |
| 2 | Mission-complete audio is primary role | **Falsified** — only `+0x1EC` branch; keyword alias rejected |
| 3 | Stack formals / `ret N` | **Falsified** — plain `C3`; ECX only |
| 4 | Returns void | **Falsified** — AL 0\|1 via `8A C3` |
| 5 | Case 4 always clears | **Falsified** — `FUN_004b6a80` non-zero breaks |
| 6 | HostTick sole caller | **Falsified** — 2 xrefs: `005179e0`, `00514d80` |
| 7 | Product name retail string | **Overstated** — `_Inferred` only |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Outer CF / five list walks | **High** | Wrong manager teardown |
| AL polarity + plain RET | **High** | Manager free bugs |
| Distinct from DeactivateClear | **High** | Double-teardown policy error |
| Nested helper semantics | **Medium** | Incomplete port of side effects |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
if host+8: return 1
switch type (if linked):
  case 4: if List1e0_AnyFlag10: break
  cases 5,6,C,D,E,14,15: if +B: early clear, keep=0
host+8 = 1
walk +1e0 / +1ec / +204 / +210 / +21c teardown
host+10 = 0
return local_8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Entry `83 EC 08 … 8B F1`; exit `C7 46 10 00… 8A C3 5B 83 C4 08 C3`.

---

## 4. Surviving contract for AutoCore

```
// ECX = fx host; plain ret; AL 0|1
// Manager prune:
if host[+9]==0 && NDSpecialFX_StopFinalize(host) != 0:
  free_fx(host)
// Do not substitute DeactivateClear — different side effects
```

Preserve case-4 AnyFlag10 **keep** break. Do not invent mission-primary naming.

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/layout sealed; nested English residual → **accept-with-gaps**.
