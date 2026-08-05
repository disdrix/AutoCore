# Review B (skeptical / adversarial): `aa_00720a40` CSoundManager_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00720a40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00720a40_CSoundManager_Ctor.md` |
| **Verdict** | **accept** on CF/init map/caller; full object layout beyond ctor writes remains **open** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a heap `operator new` + ctor combo | No alloc; returns input pointer; GetInstance passes static | **Falsified** — in-place init only |
| 2 | Multiple callers / re-init safe | Only GetInstance; once-bit is external | **Survives** — re-call would re-`InitializeCriticalSection` (unsafe); once-bit is required |
| 3 | `DAT_00aaa668` is something other than −1.0f | `read_memory` → `00 00 80 bf` | **Falsified** — −1.0f sealed |
| 4 | Zero loop length wrong (0x32 vs 50 decimal confusion) | `mov ecx, 0x32` + `rep stosd`; 0x90+0xC8=0x158 | **Survives as 50 dwords** — ends at first CS |
| 5 | Critical sections overlap or wrong base | 0x158 + 0x18 = 0x170; +0x18 = 0x188 | **Survives** — Win32 CS size 0x18 |
| 6 | All fields through +0x188 are written | Gaps at +0x18, +0x2c, +0x40, +0x50, +0x60, +0x70 | **Falsified if claimed full memset** — selective stores only |
| 7 | Object fully constructed for methods at +0x258 | Ctor stops ~+0x188 explicit; rest relies on BSS | **Open / partial** — OK for static singleton; not OK if heap without zeroing |
| 8 | Name is PDB `CSoundManager::CSoundManager` | No PDB; family from sibling string | **Not sealed** — Probable `Ctor` |
| 9 | This is map/VOGMapText related | Prior auto-alias from distant xref seed | **Falsified** — sole caller is sound GetInstance |
| 10 | Runtime verified | Static only | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| In-place + return this + ret 4 | **Confirmed** | Wrong lifetime / CC |
| −1.0f to +0x20/+0x24 | **Confirmed** | Audio scale/clamp defaults wrong |
| CS pair +0x158 / +0x170 | **Confirmed** | Deadlock / invalid CS |
| 50-dword zero @ +0x90 | **Confirmed** | Residual garbage in mid object |
| Sole caller GetInstance | **Confirmed** | Missed alternate init path |
| Product family audio manager | **High** | Mis-bucket into map text |
| Full sizeof / late method slots | **Medium–Low** | Incomplete port of play/stop family |
| English `Ctor` name | **Medium** | Docs only |

---

## 3. Cross-check against raw

```text
// raw ≡ live decompile skeleton
uVar1 = DAT_00aaa668;           // -1.0f
// SEH...
*(self+0xc)=0; self[0x10]=1; ... self[0x19]=1;
*(self+0x1c)=0; *(self+0x20)=uVar1; *(self+0x24)=uVar1; ...
// zero 0x32 dwords @ +0x90
InitializeCriticalSection(self+0x158);
InitializeCriticalSection(self+0x170);
self[1]=0; *self=1; *(self+4)=0; *(self+8)=0;
return self;
```

Epilogue bytes @ `0x00720b40`: `add esp,0x0c; ret 4`.

GetInstance contract (sibling dual) still requires once-bit — **this unit must not be called twice** on the same storage without DeleteCriticalSection.

---

## 4. Surviving contract for AutoCore

```
CSoundManager_Ctor(self) -> self
  // in-place; stdcall 1 arg
  // writes selective fields (NOT full sizeof memset)
  // self+0x20 = self+0x24 = -1.0f (DAT_00aaa668)
  // zero 50 dwords at +0x90
  // InitializeCriticalSection(+0x158), (+0x170)
  // self[0]=1, self[1]=0, +4/+8=0

// Called exactly once per process via GetInstance once-bit
// Storage: DAT_00d20070 (BSS zero-fills untouched gaps)
```

**Port tests:**

* After ctor, +0x20 and +0x24 are −1.0f; +0x1c is 0.0f.
* +0x90…+0x157 are zero; CS objects at +0x158/+0x170 are valid (Enter/Leave succeed).
* `self[0]==1`, `self[1]==0`.
* Second ctor without DeleteCriticalSection is **undefined** (match retail: prevented by once-bit).

---

## 5. Open questions

1. Semantic meaning of −1.0f pair (volume floor? disabled channel marker?).
2. Exact singleton BSS size (distance to `DAT_00d20200` / neighboring tables).
3. Atexit `LAB_009c3720` must pair `DeleteCriticalSection` — verify in that dual.
4. Any non-GetInstance construction (none found in callers list).

**Verdict:** **accept** — adversarial review seals selective-init ctor; do not document as full-object memset or heap ctor. Full late layout remains sibling work.
