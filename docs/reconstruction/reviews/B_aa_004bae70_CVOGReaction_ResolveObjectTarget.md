# Review B (skeptical / adversarial): `aa_004bae70` CVOGReaction_ResolveObjectTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae70` |
| **VA** | `0x004bae70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual **strengthen**; first dual 2026-07-23) |
| **Counterpart** | `reviews/A_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| **Evidence** | Adversarial re-read of raw + **image bytes** (`read_memory` body + `FUN_004e3260`); cross-check callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always finds object by id | **Falsified** | Invalid sentinel; domain flags off; table miss → 0 |
| 2 | Ignores only one half == -1 | **Falsified** | Need **both** halves all-ones (`(lo&hi)==-1`) |
| 3 | Single global object map | **Falsified** | **Two** tables: `ctx+4` vs `ctx+8` selected by `bGlobal` |
| 4 | Decompiler is complete CF | **Falsified** | Decompiler omits `mov ecx,[ecx+4|8]` before lookup |
| 5 | Performs spawn/remove | **Falsified** | Pure load/call/return |
| 6 | Clean/raw scaffold had extra logging | **Falsified** | No side channels |
| 7 | Server-only resolver | **Falsified** | Massive client call fan-in (Recv*, skills, UI) |
| 8 | Leading `0` in RemoveObject is “ctx” | **Falsified** | Stack arg0 = `bGlobal`; ctx is ECX |
| 9 | `FUN_004e3260` is free function (no this) | **Falsified** | Image uses ECX mask/buckets; Resolve reloads ECX |
| 10 | mode flag offsets swapped (+0xc for local) | **Falsified** | Bytes: `bGlobal!=0` → `+0xc`/`+4`; `==0` → `+0xd`/`+8` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate CF + dual-table select | **High** (image) | Resolve wrong domain / always-null |
| Invalid id pair semantics | **High** | False “missing object” vs bad TFID |
| `FUN_004e3260` returns node+0xc object* | **High** | Wrong pointer type downstream |
| Flag English / who arms +0xc/+0xd | **Tentative** | Silent resolve failure in edge boot states |
| Table product identity | **Open** | Mis-name in port; behavior still portable if both tables wired |

---

## 3. Cross-check spine (must match image)

```
if (coidLo & coidHi) == 0xFFFFFFFF: return 0
if bGlobal != 0:
  if !ctx[+0xc]: return 0
  return HashLookup(*(ctx+4), coidLo, coidHi)   // FUN_004e3260 thiscall
else:
  if !ctx[+0xd]: return 0
  return HashLookup(*(ctx+8), coidLo, coidHi)
```

Scaffold decompile / early clean matched the **if/flag** structure but **not** the table pointer loads. Strengthen pass corrects clean + duals to image.

---

## 4. Surviving contract for AutoCore

```
ResolveObjectTarget(ctx, bGlobal, coidLo, coidHi) -> object*|null
  permissioned dual-hash TFID resolve
  bGlobal selects (flag+0xc, table+0x4) vs (flag+0xd, table+0x8)
  no mutation
```

Port requirement: **two** id→object maps (or one map with a domain key equivalent), plus enable gates if flags are not always true.

---

## 5. Open questions

1. Product names for the two hash tables and `FUN_004e3260`.
2. Whether `bGlobal` is strictly TFID global bit or a broader “domain” enum (callers pass byte; non-zero vs zero only tested).
3. Init path that sets `ctx+0xc` / `ctx+0xd`.
4. Runtime: frequency of global vs local hits; miss behavior in skills vs remove.
5. Relation of `ctx+0xe5c0` removal-hash (RemoveObject) vs resolve tables at `+4`/`+8` — **sibling layout, not this unit’s body**.

**Verdict:** **accept-with-gaps**. Treat residual `FUN_*` names and flag English as open; **do not** trust decompiler alone for this unit — image sealed the dual-table switch.
