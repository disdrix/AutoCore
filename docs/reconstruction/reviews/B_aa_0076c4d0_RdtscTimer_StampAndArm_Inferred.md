# Review B (skeptical / adversarial): `aa_0076c4d0` RdtscTimer_StampAndArm_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c4d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-D) |
| **Counterpart** | `reviews/A_aa_0076c4d0_RdtscTimer_StampAndArm_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a full timer constructor | **Falsified** — no zeroing, no period math; only RDTSC + flag (init is `FUN_0076c500`) |
| 2 | This is a QueryPerformanceCounter wrapper | **Falsified** — opcode is `0F 31` RDTSC, not API call |
| 3 | cdecl / stack this | **Falsified** — stores use `ECX` base (`89 41 08`) |
| 4 | stdcall with cleanup of formals | **Falsified** — bare `C3` after `ADD ESP,8` of own frame only |
| 5 | Writes only low 32-bit stamp | **Falsified** — both `+8` and `+0xC` written from EAX/EDX |
| 6 | Flag is at `+0x10` or nested HostBase field | **Falsified** — `C6 41 18 01` is `this+0x18` on the ECX object |
| 7 | CWndVehicle-only API | **Falsified** — ~90 xrefs including HostBase ctor and non-vehicle UI/drive |
| 8 | Product name gfxPerfGraph method | **Falsified** — scaffold alias only; no string/RTTI on this leaf |
| 9 | Same unit as thunk `0x0076c5c0` | **Falsified** — thunk is separate entry that jumps/calls into this body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf RDTSC stamp role | **High** | Wrong timing primitive in port |
| ECX this + bare RET | **High** | ABI corruption |
| Offsets +8/+0xC/+0x18 | **High** | Layout mismatch |
| Product timer class English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_0076c4d0:
// SUB ESP,8
// RDTSC
// [ESP]=EAX; [ESP+4]=EDX; reload
// [ECX+8]=EAX; [ECX+0xC]=EDX
// BYTE [ECX+0x18]=1
// ADD ESP,8; RET
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF.  
`read_memory` full 33 B sealed.  
Caller HostBase: stamp applied to `this+0x10` after `FUN_0076c500(1000)`.  
Caller CWndVehicle: stamp on `nested+0x10` after flag/copy plate.

---

## 4. Surviving contract for AutoCore

```
// Port as leaf timer stamp (not full ctor):
void RdtscTimer_StampAndArm(void* timer) {
  uint64_t t = read_tsc(); // RDTSC
  *(uint32_t*)((char*)timer + 0x08) = (uint32_t)t;
  *(uint32_t*)((char*)timer + 0x0C) = (uint32_t)(t >> 32);
  *((uint8_t*)timer + 0x18) = 1;
}
// Pair with FUN_0076c500 for first-time init; do not invent product class name.
```

---

## 5. Verdict

**accept-with-gaps** — adversarial probes on role/ABI/offsets/scope falsified; product English remains open. Terminal **false**.
