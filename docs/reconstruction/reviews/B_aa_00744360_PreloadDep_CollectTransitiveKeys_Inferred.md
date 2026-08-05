# Review B (skeptical / adversarial): `PreloadDep_CollectTransitiveKeys_Inferred` / `FUN_00744360` @ `0x00744360`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00744360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-L) |
| **Counterpart** | `reviews/A_aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Bare ret / cdecl only | **Falsified** — epilogue `C2 08 00` (RET 8) |
| 2 | PushFront uses host as container | **Falsified** — after recurse, `MOV ECX,ESI` where ESI reloaded to ring (`param_2`) |
| 3 | Linear list walk only | **Falsified** — nil@`+0x25` + L/R/P is std map/set successor |
| 4 | Push without recurse | **Falsified** — self-call before PushFront |
| 5 | No membership check | **Falsified** — reverse ring scan with page wrap before insert |
| 6 | Retail product symbol sealed | **Overstated** — `_Inferred` required; no plate string |
| 7 | Scaffold assManager plate | **Rejected** — no assManager strings in body |
| 8 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX+RET8+2 stack | **High** | Stack corruption on port |
| Ring membership / push_front | **High** | Dup keys / wrong order |
| Tree equal-range + successor | **High** | Missed / infinite walk |
| Recursion order | **High** | Incomplete transitive set |
| Product English | **Medium** | Docs only |
| Runtime / cycles | **Open** | Deep graphs |

---

## 3. Cross-check against raw + bytes

Body hex (253 B) ends:

```
5F 5D 5E 5B 83 C4 18 C2 08 00
```

Live decompile ≡ 2026-07-23 raw for membership/recurse/push/successor CF. Decompiler elides EAX-out of `FUN_00426f60`/`FUN_0044d960` and ECX of PushFront — **bytes win**.

---

## 4. Surviving contract for AutoCore

```
// PreloadDep_CollectTransitiveKeys — ECX dep-tree host (tree @ +0x10)
// stack: (const int* key, GuardedVectorHeader* ring); RET 8
// equal_range(key); for each node:
//   if ring contains *(node+0x18): skip
//   else recurse(node_key, ring); PushFront(ring, node_key)
// Do not invent plate product name; keep _Inferred
// Callers: FillPreloadList, AssPreloader IsKeyTrackedRecursive family
```

---

## 5. Verdict

Adversarial pass **confirms** A on structural CF/ABI; product residual remains → **accept-with-gaps**.
