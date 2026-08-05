# Review B (skeptical / adversarial): `aa_0060b870` CVOGRegionMissions_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-B) |
| **Counterpart** | `reviews/A_aa_0060b870_CVOGRegionMissions_ctor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function allocates the 0x10 wrapper (`operator_new(0x10)`) | **Falsified** — only constructs into caller-provided `this`; Ensure does `new(0x10)` |
| 2 | Returns primary hash `*this` not wrapper | **Falsified** — `mov eax, ebp` returns wrapper |
| 3 | Stores result at owner `+0xf18` | **Falsified** — no owner pointer in body |
| 4 | Always uses DB path | **Falsified** — preload vector gate first |
| 5 | Both extended hashes get same key type | **Falsified** — `[2]` uses dword `+0x88` (gated ≠ -1); `[3]` uses byte `+0x86` |
| 6 | Objective inserts go to primary hash | **Falsified** — `FUN_0053c460` with `ECX=[ebp+4]` |
| 7 | `FUN_0060c010` this-ptr ambiguous | **Falsified by bytes** — explicit `mov ecx,[ebp+8]` / `[ebp+0xC]` |
| 8 | cdecl / no this | **Falsified** — `mov ebp,ecx` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wrapper 0x10 / four slots | **High** | Wrong mission lookup table in ports |
| Preload vs DB dual path | **High** | Double-load or empty tables |
| Insert routing this-ptrs | **High** | Missions invisible to wrong index |
| Does not own Ensure/store | **High** | Double-ctor or leak at +0xf18 |
| Secondary key semantics | **Low–Med** | Wrong index for region/type filters — product gloss open |

---

## 3. Cross-check against raw + bytes

```
if preload empty: DB load rows
build this[0..3] hashes
for each def:
  insert mission → this[0]
  maybe insert key+0x88 → this[2]
  insert key+0x86 → this[3]
  for each objective: insert → this[1]
return this
```

Clean must **not** invent owner store, single-hash layout, or merge Ensure into this unit.

---

## 4. Surviving contract for AutoCore

```c
// Port: construct region mission tables (client VOGRegionMissions)
struct CVOGRegionMissions {
  void* missionById;    // +0x00 CNDHash
  void* objectiveById;  // +0x04 CNDHash
  void* indexA;         // +0x08
  void* indexB;         // +0x0C
};

CVOGRegionMissions* CVOGRegionMissions_ctor(CVOGRegionMissions* self) {
  // 1) source defs from preload vector OR DB
  // 2) construct four hashes
  // 3) index each def + objectives
  return self;
}

// Caller (Mission_EnsureRegionMissions):
//   if (!owner->regionMissions)  // +0xf18
//     owner->regionMissions = CVOGRegionMissions_ctor(new CVOGRegionMissions);
//   return owner->regionMissions;  // wrapper*, callers *wrapper for primary hash
```

---

## 5. Open questions

1. Product meaning of `def[+0x86]` / `def[+0x88]` index keys.
2. Whether preload vector is always WAD/clonebase-filled before first Ensure.
3. Runtime OOM continuation after log-only `VOG_DEBUG_STOP`.

**Verdict:** **accept**
