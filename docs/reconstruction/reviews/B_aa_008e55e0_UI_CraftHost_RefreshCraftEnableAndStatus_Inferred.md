# Review B (skeptical / adversarial): `aa_008e55e0` UI_CraftHost_RefreshCraftEnableAndStatus (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e55e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R13-015) |
| **Counterpart** | `reviews/A_aa_008e55e0_UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall host (like bind `008e5990`) | **Falsified** — prolog `MOV EBX,EAX`; all 3 sites `MOV EAX,host; CALL`; no `MOV reg,ECX` for host |
| 2 | EDI-host (like material list `008e5e00`) | **Falsified** — entry captures **EAX**, not EDI; EDI used as scratch (REP STOSD dest / money lo) |
| 3 | Stack host / stdcall RET 4 | **Falsified** — exit `C3` plain RET; no stack arg loads |
| 4 | Is material-list refresh / TFID bind / tier-max leaf | **Falsified** — distinct callees and strings; parent dual `00520340` is only a discarded probe; bind/list are siblings |
| 5 | Mission-UI-only (Named_CalleeOf RefreshOpen scaffold) | **Falsified** — also called from craft bind tail `008e5caa` and craft tick `008e63e3` |
| 6 | Decompiler `local_214[0] == 5.60519e-45` is float physics | **Falsified** — asm `CMP ECX,0x4` / `0x2` / `0x5` on status dword from `0052d450` out-param |
| 7 | Success path prints live chance from `0052d450` out-float | **Falsified** — success path `FLD qword [DAT_00aaa708]` (**100.0**); out-param used as **int status** on fail ladder |
| 8 | Tier loop stores max capacities into host | **Falsified** — `CALL 00520340` with no store of EAX; pure discard |
| 9 | Cost uses floor / raw sell price / 1.0 scale | **Falsified** — `FMUL [aaa680]` **0.85f** then CRT `ceil` then FISTP |
| 10 | Credits compare is 32-bit only | **Falsified** — `SUB/SBB` on `+0x720/+0x724` vs `+0x728/+0x72c`; `CDQ` + 64-bit compare |
| 11 | Always enables craft button | **Falsified** — four-way AND gate; disable path calls vtbl+`0xd4`(0) when was enabled |
| 12 | Product name sealed from RTTI | **Fails** — no RTTI in unit → `_Inferred` required |
| 13 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX host + plain RET | **High** | Wrong ABI / register smash |
| Enable AND of readiness/station/`+0x7d8`/afford | **High** | Port enables craft when blocked |
| ceil(price×0.85) vs i64 credits | **High** | Wrong memory-craft cost UX |
| Status codes 2/4/5 integer | **High** | Broken message ladder |
| Success UI 100.0% hardcode | **High** | Wrong success-chance display |
| Not bind / not material list | **High** | Merge wrong host ops |
| Helper English (`54a0`/`52d450`/`202d0`) | **Med** (not OWN) | Edge-case status text |
| Craft host product class name | **Med** (family duals) | Naming only |
| Discarded tier-max loop intent | **Open** | Dead code vs hidden side effect (leaf is read-only dual) |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Call sites (get_assembly_context):
//   008e5ca8: MOV EAX,ESI ; CALL 008e55e0   (BindResolvedObject host)
//   0093a9bf: MOV EAX,EDI ; CALL 008e55e0   (RefreshOpenMissionUiWindows panel)
//   008e63e1: MOV EAX,EDI ; CALL 008e55e0   (craft tick / orphan body)
// Entry:
//   MOV EBX,EAX
// Exit:
//   POP EDI; POP ESI; POP EBX; MOV ESP,EBP; POP EBP; RET
// Next function pad:
//   CC CC ; FUN_008e5990 SEH prolog 6A FF …
// DAT_00aaa680: 9a 99 59 3f => 0.85f
// DAT_00aaa708: 00 00 00 00 00 00 59 40 => 100.0 double
// Status fail ladder (asm, not decompiler floats):
//   CMP [out],4 → FUN_008e3820
//   CMP [out],2 → "You don't have the right components!"
//   CMP afford,0 → "To craft this from Memory costs" + paint
//   CMP station,0 | CMP [out],5 → FUN_008e3940
//   else → Chance of Success %i%%
```

A ≡ B on live decompile + full disasm + xref assembly_context + constant bytes.

---

## 4. Surviving contract for AutoCore

```text
// Port as craft-host enable + status refresh:
// - input: host in EAX; no stack args; plain RET
// - early-out if global character DAT_00d1b6d8 == 0
// - set host+0x7d8 = 1; call residual FUN_008e54a0
// - optional: call Character_CalcCommodityTierMaxCapacity(char, tier) for tier=1..5 (returns unused)
// - stationOK = Character_Craft_HasMatchingStationInRange(char, host+0x7cc)
// - if FUN_005202d0(char, tfid): cost = ceil(Item_GetStoreSellPrice(obj) * 0.85); afford = credits64 >= cost
// - ready = FUN_0052d450(char, obj, &status)
// - enable craft button only if ready && stationOK && host+0x7d8 && afford
// - else disable button (if was on) and fill status message from product strings / status codes
// - always refresh status color, Complexity UI (008e41b0), button, status widget
// - do NOT merge with material-list refresh (008e5e00) or bind (008e5990/008e5ce0)
// - do NOT treat decompiler float compares as real floats
// - do NOT claim Runtime Confirmed
// - name remains _Inferred (no RTTI)
```

---

## 5. Verdict

Adversarial pass confirms A's EAX-host ABI, enable/status CF, cost formula, credits i64 compare, integer status ladder, call-site patterns, and separation from bind/list/tier-max. Rejects ECX/EDI-host, mission-only scaffold, float-poison status, live-chance-on-success, and runtime-confirmed overclaims. Residual helper English + product demangle + discarded loop intent → **accept-with-gaps**.
