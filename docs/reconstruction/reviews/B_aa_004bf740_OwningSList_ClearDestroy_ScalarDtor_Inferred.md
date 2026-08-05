# Review B (skeptical / adversarial): `OwningSList_ClearDestroy_ScalarDtor_Inferred` / `FUN_004bf740` @ `0x004bf740`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bf740` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-B) |
| **Counterpart** | `reviews/A_aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Non-owning list (just unlink, no free) | **Falsified** — `push 1; call [vtbl]` is classic MSVC scalar-deleting dtor |
| 2 | Doubly-linked / std::list sentinel | **Falsified** — only next@+4; no prev; no sentinel walk |
| 3 | Frees the list host | **Falsified** — host not deleted; bare ret after loop |
| 4 | Count field is size@+8 | **Falsified** — bytes touch `+0x0c` only for count |
| 5 | Multiple CALL sites / vtbl export | **Falsified** — sole CALL xref `004be321` |
| 6 | Product name retail | **Overstated** — `_Inferred` required |
| 7 | VOG_DEBUG scaffold plate | **Rejected** — no debug stop in body |
| 8 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Loop / dtor / count CF | **High** | Leaks or double-free on port |
| thiscall ECX host | **High** | Wrong object |
| head@+4 / next@node+4 / count@+0xc | **High** | Layout mismatch |
| Scalar dtor flags=1 | **High** | Memory leak if flags=0 assumed |
| Product English / T | **Medium** | Docs only |
| Runtime | **Open** | Edge empty/corrupt count |

---

## 3. Cross-check against raw + bytes

Body hex (47 B):

```
56 8B F1 83 7E 04 00 74 24 8D A4 24 00 00 00 00
8B 4E 04 85 C9 74 10 8B 41 04 89 46 04 8B 11 6A
01 FF 12 83 46 0C FF 83 7E 04 00 75 E3 5E C3
```

Live decompile ≡ 2026-07-23 raw. Inner null check after outer head test is redundant but present in both decompile and bytes (`85 C9; 74 10`).

---

## 4. Surviving contract for AutoCore

```
// Owning SList clear — MUST call scalar deleting dtor (flags=1) per node
// host+0x04 = head; node+0x04 = next; host+0x0c = count
// Do NOT free host here
// Sole known owner path: ListTrackedObj_CompleteDtor(this+0x10) when flag@+0x5D0
// Reject VOG_DEBUG scaffold alias
```

---

## 5. Verdict

Adversarial pass **confirms** A on structural CF/ABI; product residual remains → **accept-with-gaps**.
