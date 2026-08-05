# Review B (skeptical / adversarial): `NDSpecialFX_ParseXmlEventNode` @ `0x004a4fa0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a4fa0` |
| **VA** | `0x004a4fa0` |
| **Body span** | `004a4fa0` – `004a617f` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_004a4fa0_NDSpecialFX_ParseXmlEventNode.md` |
| **System** | `client-fx` / NDSpecialFX |
| **Verdict** | **accept-with-gaps** on string tables + dispatch + key offsets; **needs-more-evidence** on decompiler child-loop packing and full Sound/Parameter field layout ports |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Arg0 is a `BSTR` | **Falsified** — prologue loads vtbl and calls `[ecx+0x44]` with node as object. |
| 2 | Function name `Drive_driver` | **Falsified** — `L"driver"` is one **Group owner** token among many; role is FX event parse. |
| 3 | Unknown event types are rejected | **Falsified** — assigned `*counter+100` and counter increments (custom events). |
| 4 | MusicEvent always parsed | **Falsified** — gated on `*outEventType == 0` (Create only). |
| 5 | Sound maxradius only from `maxradius` | **Overstated** — tries `maxradius` then `maxRadius`; else restores `DAT_009c7c2c` (80.f). |
| 6 | weaponMelee miss → id 0x15 | **Falsified** — formula yields **0** when `wcsicmp != 0`. |
| 7 | Parameter type `number` → 3 | **Falsified** — match → **2**; else → **3** (`3 - (neq!=0)`). |
| 8 | Clean is a drop-in binary clone of the 0x958 frame | **Falsified** — clean is CF/table map; loop condition intentionally stubbed as residual packing. |
| 9 | Fail always returns NULL without free | **Overstated** — some paths `FUN_004b99c0`+`operator_delete` (noreturn); early gates free BSTRs and return NULL. |
| 10 | Runtime verified | **Falsified** — open. |
| 11 | `fx` null after failed `operator_new` is safe | **Risk** — retail still stores through `pvVar5` if new returns null (decomp); ports should treat as UB / crash parity. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl / 3 stack args / FX* return | **High** | ABI break |
| Event-type string table values | **High** | Wrong FX class / sound category coupling |
| Custom id base 100 + counter++ | **High** | ID collision with fixed 0–23 |
| Group owner ids | **High** | Wrong attach points on vehicles |
| `fx+0x28` event type | **High** | Downstream switch bugs |
| Sound defaults 10/80 + category switch | **High** | Audio radius wrong |
| Child element **set** and fail policies | **High** | Missing content type |
| Exact Sound field offsets beyond listed | **Medium** | Attr write wrong slot |
| Child enumerator count source | **Low–Medium** | Infinite/short loop if mis-ported from decomp locals |
| Callee bodies | **Out of scope** | Do not invent Particle/Trail semantics here |

---

## 3. Surviving contract for AutoCore

```
fx = NDSpecialFX_ParseXmlEventNode(node, &eventType, &customCounter):
  if !node.openAttrs(...): return NULL
  if !readTypeName(wide): return NULL
  eventType = mapType(wide) or (customCounter+100; customCounter++)
  fx = new NDSpecialFX_shell(0x240)   // FUN_004ba310
  fx.eventType = eventType            // +0x28
  optional fx.float58 = ...
  children = node.enumChildren(...)
  if !children: teardown; delete fx    // noreturn
  for each child:
    switch elementName:
      Group:      map owner → attachId; register group
      Particle:   load or teardown
      Geometry:   load
      Trail:      load or teardown; link parent/group
      Lightning:  load or teardown; link
      Sound:      0x138 block + attrs + validate + attach
      MusicEvent: only if eventType==Create; 200-byte block
      Force:      fx.force = ...; force.parent = fx
      Include:    load or teardown
      Parameter:  0x28 block + type map + insert
      Fluid:      if global flag; load or teardown
  return fx
```

**Port rules that survive adversarial review:**

1. Keep the **full event-type and group-owner tables** bit-identical to retail strings/values.
2. Preserve **custom event id** allocation (`base 100 + counter`).
3. Do not parse MusicEvent for non-Create events.
4. On Particle/Include/Trail/Lightning/Fluid hard fail, match teardown+delete (no silent half-object).
5. Leave child loader internals as hooks until those VAs are dual-owned.
6. Do not trust Ghidra `BSTR` prototype or `Drive_driver` alias.

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs raw body | **Match** (string tables + dispatch) |
| Live constants vs `read_memory` | **Match** (`top`, 10.f, 80.f) |
| Clean tables vs decompile | **Match** |
| Clean full stack frame | **Not claimed** — structural map only |
| Xrefs = 3 FX loaders | **Match** |

---

## 5. Open questions (OWN residual only)

1. Exact product name for vtbl `+0x44` (get attribute vs open element).
2. Whether `FUN_004b6850` must run before children for all event types (call present — body residual).
3. Whether null `operator_new` path is reachable under retail allocator (if yes, crash parity).
4. Full Sound `soundType` secondary map (Generic / ENGINE_MY_* / Weather…) field values — present in decompile; clean summarizes — re-expand if audio port needs every code.

**Verdict:** **accept-with-gaps** on OWN high-value CF (type/owner tables, dispatch, key FX offsets, fail policies). **needs-more-evidence** before treating clean as a complete line-accurate implementation of the child loop or every Sound/Parameter byte offset. Safe behavioral map for AutoCore FX event loading once callee hooks and residual packing are respected.
