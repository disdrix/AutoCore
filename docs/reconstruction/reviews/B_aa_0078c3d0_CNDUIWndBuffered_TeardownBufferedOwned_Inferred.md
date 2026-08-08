# Review B (skeptical / adversarial): `aa_0078c3d0` CNDUIWndBuffered_TeardownBufferedOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078c3d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-D2) |
| **Counterpart** | `reviews/A_aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete destructor of CNDUIWndBuffered | **Falsified** — no vtbl reinstall, no SEH, no base chain; parent `0078ca80` owns complete-dtor plate |
| 2 | This frees HostBase at `+0x2A8` | **Falsified** — only reads HostBase; parent complete dtor scalar-deletes `+0x2A8` **after** this returns |
| 3 | cdecl / stack `this` | **Falsified** — entry `MOV ESI,ECX`; bare `C3` |
| 4 | stdcall with stack cleanup of formals | **Falsified** — no `RET n`; no stack formals |
| 5 | `FUN_0074e260` is free-standing with only stack arg | **Falsified** — bytes set `ECX = *(*(this+0x2A8)+4)` before each CALL |
| 6 | Always tears down `+0x49C` | **Falsified** — gated by non-null `+0x49C` after gate `+0x2A4` |
| 7 | Gate is `+0x2AC` or `+0x2A8` | **Falsified** — first CMP is `[ESI+0x2A4]` |
| 8 | Refcount uses `AddRef`/`Release` COM IUnknown layout fully | **Partial** — shape is refcount@`+4` + vcall@`+8`; full IUnknown product identity open |
| 9 | Product method demangle sealed | **Open** — class sealed via parent RTTI; method English inferred only |
| 10 | CWndVehicle-only helper | **Falsified** — lives on CNDUIWndBuffered complete path; CWndVehicle is one derived caller of parent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Helper role under complete dtor | **High** | Wrong lifecycle ownership in port |
| ECX this + bare RET | **High** | ABI corruption |
| Offsets 0x2A4/0x2A8/0x2AC/0x49C | **High** | Layout mismatch / double-free |
| Unregister thiscall this=`HostBase+4` | **High** | Wrong registry object |
| Scalar-delete flag 1 | **High** | Leak vs double-free |
| Product child type English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_0078c3d0:
// ESI=ECX; EDI=0
// if [ESI+0x2A4]==0: RET
// CALL FUN_0074e260 with ECX=*( [ESI+0x2A8] +4 ), arg=*([ESI+0x2AC]+0x8C)
// optional vtbl[0](1) on +0x2AC; null +0x2AC
// optional same for +0x49C
// optional vtbl[0](1) on +0x2A4; null +0x2A4
// refcount release on *(*(HostBase+4)+0x3C); null slot
// RET
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF.  
`read_memory` full 175 B sealed.  
Call site in complete dtor: `MOV ECX,ESI; CALL 0078c3d0` then HostBase free.

Parent dual already documented this VA as residual helper English gap — now sealed under `_Inferred`.

---

## 4. Surviving contract for AutoCore

```
// Port as complete-dtor helper (not complete dtor itself):
void CNDUIWndBuffered_TeardownBufferedOwned(void* self) {
  if (*(void**)((char*)self + 0x2A4) == nullptr) return;
  // unregister+delete +0x2AC; optional +0x49C;
  // delete +0x2A4; release HostBase_aux+0x3C;
  // DO NOT free +0x2A8 here — parent complete dtor owns that.
}
// Pair with CNDUIWndBuffered_CompleteDtor (0x0078ca80) and ctor (0x0078caf0).
// Do not invent product names for owned child types without RTTI/strings.
```

---

## 5. Verdict

**accept-with-gaps** — adversarial probes on complete-dtor merge, HostBase free, ABI, gate offset, and unregister thiscall **falsified** against claims; product child-type English remains open. Terminal **false**.
