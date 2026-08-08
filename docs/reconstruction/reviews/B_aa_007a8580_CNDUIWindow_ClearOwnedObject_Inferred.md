# Review B (skeptical / adversarial): `aa_007a8580` CNDUIWindow_ClearOwnedObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a8580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-E) |
| **Counterpart** | `reviews/A_aa_007a8580_CNDUIWindow_ClearOwnedObject_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is complete dtor of CNDUIWindow | **Falsified** — no vtbl reinstall, no free chain, bare clear of one slot; complete is `0x007b5be0` |
| 2 | Frees `this` / operator_delete | **Falsified** — bare `RET`; no delete of host |
| 3 | Child `+0x2B4` is always deleted | **Falsified** — flags=0 only (dtor without free) |
| 4 | Always deletes object at `+0x298` | **Falsified** — delete only when `+0xBC` set; else abandon-null |
| 5 | cdecl / stack this | **Falsified** — `MOV ESI,ECX` |
| 6 | Scaffold name "CalleeOf VOG_DEBUG_STOP" is product | **Falsified** — parent logs VOG; this unit has no string; structural clear method |
| 7 | Set pair is same function | **Falsified** — `FUN_007a85e0` distinct body; calls this via vtbl+0x44 |
| 8 | `DAT_00a1419b` is non-empty format string | **Falsified** — first byte `0x00` empty C-string |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX-this / bare RET | **High** | Wrong call convention |
| Offsets +0x298 / +0x2B4 / +0xBC | **High** | Wrong layout port |
| flags=0 vs flags=1 split | **High** | Double-free / leak |
| Always-null +0x298 | **High** | Dangling non-owned ptr |
| Product English of owned type | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

Live 2026-08-05 decompile ≡ raw 2026-07-23 CF. Disasm seals dword `+0x298` vs decompiler index `0xa6`, byte `+0xBC` vs `(char)param_1[0x2f]`. Set pair `007a85e0` confirms clear-then-store contract.

---

## 4. Surviving contract for AutoCore

```
// Virtual clear of owned object slot (vtbl +0x44):
CNDUIWindow_ClearOwnedObject_Inferred(window);
// Pair: Set at vtbl +0x40 (FUN_007a85e0) calls clear first.
// Complete dtor calls this before aec70/aff00 free chain.
```

---

## 5. Verdict

Adversarial attacks on dtor/free/always-delete/cdecl claims fail. Residual product type English only → **accept-with-gaps**. Terminal **false**.
