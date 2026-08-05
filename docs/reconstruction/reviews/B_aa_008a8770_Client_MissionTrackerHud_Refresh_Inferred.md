# Review B (skeptical / adversarial): `Client_MissionTrackerHud_Refresh_Inferred` @ `0x008a8770`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a8770` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-F OWN dual) |
| **Counterpart** | `reviews/A_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md` |
| **Verdict** | **accept-with-gaps** — chrome multi-arm holds; string-only name **broken** |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | Function **is** `Mission_Look_in_your_Mission_Inventory` | **Oversell** — that string is one instruction-buffer branch when mission-inventory probe `FUN_005710c0` hits; body also does title, "Next mission", journal, Go to, distance, materials | **Retracted as sole name.** Role name with `_Inferred` |
| 2 | This is a **mission wire** or complete-objective handler | **False** — no `Client_SendSectorPacket` / opcode literals; callees are hash/UI/math/string | **Hold chrome-only** |
| 3 | `param_1` is the **character** | **False friend** — character is `DAT_00d1b6d8`; `param_1` is HUD host with widgets at large dword indices | **Hold host UI object** |
| 4 | Always shows distance | **False** — distance arm only when `FUN_0092c810() >= 1`; else instruction text arm | **Hold split** |
| 5 | `FUN_0092c810` meaning is sealed | **Open** — only comparison shape sealed; product predicate English residual | **Gap** |
| 6 | Widget offsets are product-named | **Inferred** — `+0x688/+0x694/+0x690` from `[0x1a2]/[0x1a5]/[0x1a4]` sealed as indices; types Tentative | **Hold offsets; open types** |
| 7 | DATA-only xref means dead code | **Weak** — common for UI method tables; invoker not required for CF seal | **Hold as live handler slot** |
| 8 | Decompiler `unaff_EBX` is a real formal | **Noise** — SEH/reg noise; not a stack arg (`ret 0`) | **Ignore as formal** |

---

## 2. Surviving contract for AutoCore

```
// Client-only mission tracker HUD refresh — NOT a server RPC
void MissionTrackerHud_Refresh(UIHost* host) {
  if (!g_localChar || g_localChar->busy_0x4f1) return;
  if (!host->title || !host->instruction || !host->icon) return;

  // 1) Title from tracker key / mission hash / "Next mission" / contact
  // 2) If !hasRangeTarget: instruction = inventory | journal | "Go to X" | empty
  // 3) Else: distance string (metric/imperial) + material tint + icon placement
  // No C2S. Server should not mirror this UI composer.
}
```

Server parity notes:

- Tracker **state** (active objective id, complete flags) is authoritative on server.
- This client function **presents** that state; do not port as gameplay authority.
- Instruction branch "Look in your Mission Inventory" is **UI hint only**.

---

## 3. Skeptical hits on residual "seals"

| Seal | Challenge | Hold? |
|---|---|---|
| Body size 3752 B | Plate end vs true end | **Hold** — meta `008a9618`; epilogue `C3` region matches |
| ECX host | Could be fastcall non-this | **Hold as thiscall-shaped** — sole register arg + method table xref |
| No net | Hidden via vtbl | **Hold High** — no packet helpers in callees list |
| String branches | Localization wrapper may rewrite | **Hold source string keys** via `FUN_007a6de0` |

---

## 4. What would falsify

1. Product PDB naming a different role (e.g. full screen mission journal paint).
2. Live call stack showing non-HUD host in ECX.
3. Discovery of a net send inside a callee unique to this path (not currently listed).

None observed in static dual.

---

## 5. Open questions

1. Product host class / method.
2. `FUN_0092c810` product meaning.
3. Owner of DATA slot `0x00a4b55c`.
4. Runtime paint verification.

**Verdict:** Adversarial review **breaks string-only name**, **does not break** multi-arm chrome CF / ABI / chrome-only claim. **accept-with-gaps.**
