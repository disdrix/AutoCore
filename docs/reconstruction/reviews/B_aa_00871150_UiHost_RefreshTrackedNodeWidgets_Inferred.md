# Review B (skeptical / adversarial): `aa_00871150` UiHost_RefreshTrackedNodeWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00871150` |
| **VA** | `0x00871150` |
| **Canonical name** | `UiHost_RefreshTrackedNodeWidgets_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00871150_UiHost_RefreshTrackedNodeWidgets_Inferred.md` |
| **System** | client UI / vehicle-garage host residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Standard thiscall (ECX=this) | Bytes: `mov esi, eax` then use ESI; callers `mov eax, esi` before call | **Falsified** ECX-this — **EAX-this** |
| 2 | Leaf / no stack frame | `sub esp, 0x108` + multi-widget | **Falsified** leaf |
| 3 | Always updates every widget | Each arm null-checks host slot | **Falsified** always |
| 4 | Node is the UI host | Callers push node; host in EAX; node fields +8/+0xc match list node | **Falsified** host=node |
| 5 | Frees or mutates node | Read-only field loads; no store to `*node` | **Attack fails** — refresh-only (clear is caller `008718a0`) |
| 6 | Selection block always runs | Requires `DAT_00d1b6d8` + pair match | **Falsified** always |
| 7 | Decomp fully reports FUN_007fd970 args | Bytes load CL from node+0x1c, sub 0x0f | **Confirmed residual** — decomp under-reports |
| 8 | 4-arg stdcall | `ret 4` only | **Falsified** 4-arg — **1 stack arg** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX-this + ret 4 | **Confirmed** | Wrong ABI → crash |
| Widget bank offsets | **Confirmed** | Wrong labels bound |
| No node free/clear here | **Confirmed** | Double-clear / UAF if port mutates |
| vtbl pack exactness | **Tentative** | Wrong text on widgets |
| Product names | **Open** | Docs only |

---

## 3. Cross-check against raw / live / bytes

```
decompile_function(0x00871150) ≡ raw authoritative body
read_memory prologue/epilogue seals ABI and FUN_007fd970 CL path
Body size Ghidra: 0x00871150–0x008715f8 (0x4A8)
Sibling 008718a0 passes host in EAX + node on stack — consistent
```

### Merge trap

Do **not** fold into `FUN_008718a0` (clear-then-refresh) or `FUN_00871690` (lookup). This VA is **rebind only**.

### Decomp trap

Do **not** trust empty `sprintf("%d")` alone as meaning "no value" — decomp drops varargs; values come from node/host via subsequent vtbl calls.

### ABI trap

Ports that place host in ECX diverge. Retail uses **EAX**.

---

## 4. Surviving contract for AutoCore

```
UiHost_RefreshTrackedNodeWidgets(host, node):
  if !host.IsVisible(): return
  if !node: return
  prep format from node+0x1c
  bind optional widgets from host+0x5e8..+0x600 using node id pair (+8,+0xc)
  if global selection pair matches: highlight those widgets

AutoCore must NOT:
  - clear or free node here
  - require all seven widgets non-null
  - use ECX as this
  - skip selection rebind when pair matches
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Multi-widget refresh from tracked node | **Agree Confirmed** |
| ABI EAX + ret 4 | **Agree Confirmed** |
| accept-with-gaps (vtbl packs / English open) | **Agree** |
| Name `_Inferred` | **Agree High** — role sealed, product open |

---

## 6. Verdict

**accept-with-gaps** — adversarial checks strengthen ABI and non-mutation; residual is product English + exact vtbl argument packs.
